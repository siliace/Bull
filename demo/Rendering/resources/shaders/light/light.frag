#version 330 core

in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 color;

void main()
{
    color = frag_color;
}