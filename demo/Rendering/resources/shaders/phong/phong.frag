#version 330 core

struct Material
{
    float     shininess;
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
};

struct DirectionalLight
{
    vec3 direction;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

struct PointLight
{
    vec3 position;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    float constant;
    float linear;
    float quadratic;
};

struct SpotLight
{
    vec3 position;
    vec3 direction;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    float constant;
    float linear;
    float quadratic;

    float innerCutOff;
    float outerCutOff;
};

in vec3 frag_position;
in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 pixel;

uniform DirectionalLight dl;
uniform PointLight       pls[3];
uniform SpotLight        sp;

uniform Material  material;

uniform vec3      eye_position;

float getAttenuation(float constant, float linear, float quadratic)
{
    float distance = length(frag_position - eye_position);

    return 1.f / (constant + linear * distance + quadratic * pow(distance, 2.f));
}

vec4 getAmbient(vec4 light)
{
    return texture(material.diffuse, frag_texCoord) * light;
}

vec4 getDiffuse(vec3 lightDirection, vec4 light)
{
    float diffuseFactor = max(dot(frag_normal, -lightDirection), 0.f);

    return texture(material.diffuse, frag_texCoord) * diffuseFactor * light;
}

vec4 getSpecular(vec3 lightDirection, vec4 light)
{
    vec3 viewDirection = normalize(frag_position - eye_position);
    vec3 reflectionDirection = reflect(lightDirection, frag_normal);

    float specularFactor = pow(max(dot(-viewDirection, reflectionDirection), 0.f), material.shininess);

    return texture(material.specular, frag_texCoord) * specularFactor * light;
}

vec4 directionalLight(DirectionalLight light)
{
    return getAmbient(light.ambient) + getDiffuse(light.direction, light.diffuse) + getSpecular(light.direction, light.specular);
}

vec4 pointLight(PointLight light)
{
    vec3 direction = normalize(frag_position - light.position);

    float attenuation = getAttenuation(light.constant, light.linear, light.quadratic);

    return (getAmbient(light.ambient) + getDiffuse(direction, light.diffuse) + getSpecular(direction, light.specular)) * attenuation;
}

vec4 spotLight(SpotLight light)
{
    float attenuation = getAttenuation(light.constant, light.linear, light.quadratic);

    float theta = dot(normalize(frag_position - light.position), light.direction);

    float epsilon   = light.innerCutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.f, 1.f);

    vec4 ambient = getAmbient(light.ambient);
    vec4 diffuse = getDiffuse(light.direction, light.diffuse) * intensity;
    vec4 specular = getSpecular(light.direction, light.specular) * intensity;

    return (ambient + diffuse + specular) * attenuation;
}

void main()
{
    vec4 color = directionalLight(dl);

    for(int i = 0; i < 3; i++)
    {
        color += pointLight(pls[i]);
    }

    color += spotLight(sp);

    pixel = color * frag_color;
}