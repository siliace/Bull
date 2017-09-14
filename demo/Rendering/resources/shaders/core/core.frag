#version 330 core

in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 pixel;

uniform sampler2D tex_wall;

void main()
{
    pixel = texture(tex_wall, frag_texCoord) * frag_color;
}