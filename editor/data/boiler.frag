#version 330 core

out vec4 color;
void main()
{
    color = vec4(1.0);
}
#version 330 core
layout(location = 0) in vec3 a_position; 

void main()
{
    gl_Position = vec4(a_position,1.0);
}
