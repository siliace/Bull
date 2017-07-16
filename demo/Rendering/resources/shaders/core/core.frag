#version 330 core

out vec4 fragColor;

uniform vec4 light;
uniform vec4 color;

void main()
{
    float ambiantStrenght = 0.1f;
    vec4 ambiant = ambiantStrenght * light;

    if(color == light)
    {
        fragColor = color;
    }
    else
    {
        fragColor = color * ambiant;
    }
}