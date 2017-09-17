#version 330 core

in vec3 frag_position;
in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 pixel;

uniform sampler2D tex_wall;
uniform vec4      light_color;
uniform vec3      light_position;
uniform vec3      camera_position;
uniform float     ambient_strength;
uniform float     specular_strength;
uniform float     specular_shininess;

vec3 normal = normalize(frag_normal);
vec3 lightDirection = normalize(light_position - frag_position);

float getSpecularity()
{
    vec3 reflectDirection = reflect(-lightDirection, normal);
    vec3 cameraDirection = normalize(camera_position - frag_position);

    return pow(max(dot(reflectDirection, cameraDirection), 0.f), specular_shininess);
}

void main()
{
    vec4 ambient  = ambient_strength * light_color;
    vec4 diffuse  = max(dot(normal, lightDirection), 0.f) * light_color;
    vec4 specular = specular_strength * getSpecularity() * light_color;

    vec4 object = texture(tex_wall, frag_texCoord) * frag_color;

    pixel = (ambient + diffuse + specular) * object;
}