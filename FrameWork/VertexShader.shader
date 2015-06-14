#version 330 core
 
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 inTexCoord;

out vec2 texCoord;
out vec2 fragPos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 texSource;


void main()
{
	fragPos = vec2(model * vec4(position, 0.0, 1.0));
	texCoord = (texSource * vec4(inTexCoord.xy, 0.0, 1.0)).xy;
	gl_Position = projection * model * vec4(position, 0.0, 1.0);
}
