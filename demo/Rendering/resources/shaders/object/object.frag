#version 330 core

in vec3 frag_position;
in vec4 frag_color;
in vec2 frag_texCoord;
in vec3 frag_normal;

out vec4 color;

uniform vec4 light;
uniform vec3 viewPosition;
uniform vec3 lightPosition;

void main()
{
    // Ambiant
    float ambiantStrenght = 0.1f;
    vec4 ambiant = light * ambiantStrenght;

    // Diffuse
    vec3 normal = normalize(frag_normal);
    vec3 lightDirection = normalize(lightPosition - frag_position);
    float diff = max(dot(normal, lightDirection), 0);
    vec4 diffuse = diff * light;

    // Specular
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(viewPosition - frag_position);
    vec3 reflectDir = reflect(-lightDirection, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0), 256);
    vec4 specular = specularStrength * spec * light;

    color = (ambiant + diffuse + specular) * frag_color;
}