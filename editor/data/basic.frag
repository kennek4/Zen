#version 460 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D image;
uniform vec3 spriteColor = vec3(1.0f, 0.0f, 0.0f);

void main()
{
    color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
}
