#version 330 core

struct Material
{
    float shininess;
    sampler2D diffuse;
    sampler2D emission;
    sampler2D specular;
};

struct Light
{
    vec3 position;
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

in vec3 frag_position;
in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 pixel;

uniform Light light;
uniform Material material;
uniform vec3 camera_position;

vec3 normal = normalize(frag_normal);
vec3 lightDirection = normalize(light.position - frag_position);

float getDiffusion()
{
    return max(dot(normal, lightDirection), 0.f);
}

float getSpecularity()
{
    vec3 reflectDirection = reflect(-lightDirection, normal);
    vec3 cameraDirection = normalize(camera_position - frag_position);

    return pow(max(dot(reflectDirection, cameraDirection), 0.f), material.shininess);
}

void main()
{
    vec4 ambient  = texture(material.diffuse, frag_texCoord) * light.ambient;
    vec4 diffuse  = texture(material.diffuse, frag_texCoord) * getDiffusion() * light.diffuse;
    vec4 specular = texture(material.specular, frag_texCoord) * getSpecularity() * light.specular;

    pixel = (ambient + diffuse + specular) * frag_color;
}