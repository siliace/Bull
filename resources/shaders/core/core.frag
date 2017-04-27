#version 330 core

in vec4 frag_color;
in vec2 frag_texCoord;

out vec4 color;

uniform sampler2D tex;

void main()
{
    color = texture(tex, frag_texCoord) * frag_color;
}