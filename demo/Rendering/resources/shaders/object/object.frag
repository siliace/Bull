#version 330 core

in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 color;

uniform vec4 light;

void main()
{
    float ambiantStrenght = 0.1f;
    vec4 ambiant = light * ambiantStrenght;

    color = frag_color * ambiant;
}