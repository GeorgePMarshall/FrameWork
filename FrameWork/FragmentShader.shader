#version 330 core

in vec2 texCoord;

out vec4 color;

uniform sampler2D inTexture;
uniform vec2 lightLocation;
uniform vec2 lightLocation2;
uniform vec3 spriteColour;


void main()
{
	
	vec2 distVec = vec2( gl_FragCoord.x - lightLocation.x, 720 - gl_FragCoord.y - lightLocation.y);
	float dist = sqrt((distVec.x * distVec.x) + (distVec.y * distVec.y));
	dist *= 0.005;
	
	float attenuation = 1.0f / (1.0f + 0.3f * dist + 0.3f * (dist * dist));
	vec3 light = vec3(spriteColour.xyz * attenuation) * vec3(0.7f, 0.2f, 0.0f);


	///////////


	vec2 distVec2 = vec2(lightLocation2.x - gl_FragCoord.x, 720 - lightLocation2.y - gl_FragCoord.y);
	float dist2 = sqrt((distVec2.x * distVec2.x) + (distVec2.y * distVec2.y));
	dist2 *= 0.005;
	
	float attenuation2 = 1.0f / (1.0f + 0.7f * dist2 + 0.3f * (dist2 * dist2));
	vec3 light2 = vec3(spriteColour.xyz * attenuation2) * vec3(0.0f, 0.6f, 0.0f);
	
	color = vec4(light + light2, 1.0f) * texture(inTexture, texCoord);
}