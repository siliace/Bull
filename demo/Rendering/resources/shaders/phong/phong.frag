#version 330 core

struct Material
{
    float shininess;
    sampler2D diffuse;
    sampler2D emission;
    sampler2D specular;
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

    float linear;
    float constant;
    float quadratic;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

struct SpotLight
{
    vec3 position;
    vec3 direction;

    float innerCutOff;
    float outerCutOff;

    float linear;
    float constant;
    float quadratic;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

in vec3 frag_position;
in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 pixel;

uniform Material material;
uniform vec3 camera_position;
uniform SpotLight light;

vec4 ambient(sampler2D ambientMap, vec2 texCoord, vec4 lightAmbient)
{
    return texture(ambientMap, texCoord) * lightAmbient;
}

vec4 diffusion(sampler2D diffuseMap, vec2 texCoord, vec3 normal, vec3 lightOrigin, vec4 lightDiffuse)
{
     float diffuseFactor = max(dot(normal, lightOrigin), 0.f);

     return texture(diffuseMap, texCoord) * diffuseFactor * lightDiffuse;
}

vec4 specularity(sampler2D specularityMap, vec3 position, vec2 texCoord, vec3 normal, vec3 lightOrigin, vec4 lightSpecular, vec3 camera)
{
    vec3 reflectDirection = reflect(-lightOrigin, normal);
    vec3 cameraDirection = normalize(camera - position);
    float specularityFactor = pow(max(dot(reflectDirection, cameraDirection), 0.f), material.shininess);

    return texture(specularityMap, texCoord) * specularityFactor * lightSpecular;
}

float attenuation(vec3 lightPosition, float constant, float linear, float quadratic, vec3 position)
{
    float distance = length(lightPosition - position);

    return 1.f / (constant + linear * distance + quadratic * pow(distance, 2.f));
}

void main()
{
    vec3 normal = normalize(frag_normal);
    vec3 lightOrigin = normalize(light.position - frag_position);

    float epsilon = light.innerCutOff - light.outerCutOff;
    float theta = dot(lightOrigin, normalize(-light.direction));
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.f, 1.f);

    vec4 ambientLight = ambient(material.diffuse, frag_texCoord, light.ambient);
    vec4 diffuseLight  = diffusion(material.diffuse, frag_texCoord, normal, lightOrigin, light.diffuse);
    vec4 specularLight = specularity(material.specular, frag_position, frag_texCoord, normal, lightOrigin, light.specular, camera_position);

    diffuseLight *= intensity;
    specularLight *= intensity;

    float attenuationFactor = attenuation(light.position, light.constant, light.linear, light.quadratic, frag_position);
    ambientLight *= attenuationFactor;
    diffuseLight *= attenuationFactor;
    specularLight *= attenuationFactor;

    pixel = (ambientLight + diffuseLight + specularLight) * frag_color;
}