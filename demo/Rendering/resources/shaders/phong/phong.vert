#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 in_texCoord;
layout(location = 3) in vec3 in_normal;

out vec3 frag_position;
out vec4 frag_color;
out vec2 frag_texCoord;
out vec3 frag_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    frag_position = vec3(model * vec4(in_position, 1.f));
    frag_color    = in_color;
    frag_texCoord = in_texCoord;
    frag_normal   = mat3(transpose(inverse(model))) * in_normal;

    gl_Position = projection * view * vec4(frag_position, 1.f);
}