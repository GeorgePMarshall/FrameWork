#version 330 core

in vec2 texCoord;

out vec4 color;

uniform sampler2D inTexture;
uniform vec3 spriteColour;

void main()
{
	color = vec4(spriteColour, 1.0) * texture(inTexture, texCoord);
}