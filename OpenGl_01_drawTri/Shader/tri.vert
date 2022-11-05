#version 410 core
layout (location = 0) in vec3 aPos;
out vec4 vertexColor;
void main()
{
    gl_Position = vec4(aPos.xyz, 1.0);
    vertexColor = vec4(0.5,0.3,0.8,1.0);
}