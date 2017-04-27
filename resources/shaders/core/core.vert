#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 in_texCoord;

out vec4 frag_color;
out vec2 frag_texCoord;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

void main()
{
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(in_position, 1.f);

    frag_color    = in_color;
    frag_texCoord = in_texCoord;
}