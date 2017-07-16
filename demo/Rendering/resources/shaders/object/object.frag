#version 330 core

in vec3 frag_position;
in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 color;

uniform vec4 light;
uniform vec3 lightPosition;

void main()
{
    // Ambiant
    float ambiantStrenght = 0.1f;
    vec4 ambiant = light * ambiantStrenght;

    // Diffuse
    vec3 normal = normalize(frag_normal);
    vec3 lightDirection = normalize(lightPosition - frag_position);
    float diff = max(dot(normal, lightDirection), 0);
    vec4 diffuse = diff * light;

    color = (ambiant + diffuse) * frag_color;
}