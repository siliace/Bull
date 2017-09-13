#version 330 core

layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec2 in_texCoord;
layout (location = 3) in vec3 in_normal;

out vec4 frag_color;
out vec2 frag_texCoord;
out vec3 frag_normal;

void main()
{
    gl_Position = vec4(in_pos, 1.f);

    frag_color    = in_color;
    frag_normal   = frag_normal;
    frag_texCoord = frag_texCoord;
}