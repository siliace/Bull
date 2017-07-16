#version 330 core

layout(location = 0) in vec3 in_position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = vec4(in_position, 1) * model * view * proj;
}