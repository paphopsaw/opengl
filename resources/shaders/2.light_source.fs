#version 330 core
out vec4 FragColor;

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


uniform Light lightCube;

void main()
{
    FragColor = vec4(lightCube.diffuse, 1.0);
}