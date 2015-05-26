#version 330 core
 
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 inTexCoord;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 texSource;


void main()
{
	texCoord = ( texSource * vec4(inTexCoord.xy, 0.0, 1.0)).xy;
	gl_Position = projection * model * vec4(position, 0.0, 1.0);
}
