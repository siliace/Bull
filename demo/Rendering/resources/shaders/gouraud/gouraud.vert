#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 in_texCoord;
layout(location = 3) in vec3 in_normal;

out vec4 frag_color;
out vec2 frag_texCoord;

uniform mat4  model;
uniform mat4  view;
uniform mat4  projection;
uniform vec4  light_color;
uniform vec3  light_position;
uniform vec3  camera_position;
uniform float ambient_strength;
uniform float specular_strength;
uniform float specular_shininess;

vec3 position = vec3(model * vec4(in_position, 1.f));
vec3 lightDirection = normalize(light_position - position);
vec3 normal = normalize(vec3(model * vec4(in_normal, 0.f)));

float getSpecularity()
{
    vec3 reflectDirection = reflect(-lightDirection, normal);
    vec3 cameraDirection = normalize(camera_position - position);

    return pow(max(dot(reflectDirection, cameraDirection), 0.f), specular_shininess);
}

void main()
{
    vec4 ambient  = ambient_strength * light_color;
    vec4 specular = specular_strength * getSpecularity() * light_color;
    vec4 diffuse  = max(dot(normal, lightDirection), 0.f) * light_color;

    gl_Position = projection * view * vec4(position, 1.f);

    frag_color    = (ambient + diffuse + specular) * in_color;
    frag_texCoord = in_texCoord;
}