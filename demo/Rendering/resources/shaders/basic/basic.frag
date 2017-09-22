#version 330 core

in vec4 frag_color;
in vec2 frag_texCoord;

out vec4 pixel;

uniform sampler2D diffuse;

void main()
{
    pixel = texture(diffuse, frag_texCoord) * frag_color;
}