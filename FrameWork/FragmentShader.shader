#version 330 core

struct Light
{
	bool initialized;
	vec2 position;
	vec3 colour;
	
	float constant;
	float linear; 
	float quadratic;
};

in vec2 texCoord;
in vec2 fragPos;
out vec4 color;

uniform sampler2D inTexture;
uniform vec3 spriteColour;
#if NUM_OF_LIGHTS > 0
uniform Light lights[NUM_OF_LIGHTS];
#endif

vec3 calculateLight(Light light, vec2 fragPos, vec3 spriteColour);

void main()
{
	vec3 totalLight;

#if NUM_OF_LIGHTS == 0
	totalLight = vec3(1.0, 1.0, 1.0);
#else
	for (int i = 0; i < NUM_OF_LIGHTS; i++)
	{
		if (lights[i].initialized)
		{
			totalLight += calculateLight(lights[i], fragPos, spriteColour);
		}
			
	}
#endif

	color = vec4(totalLight, 1.0f) * texture(inTexture, texCoord);
}

vec3 calculateLight(Light light, vec2 fragPos, vec3 spriteColour)
{
	float dist = length(light.position - fragPos);
	//dist *= 0.005;

	float attenuation = 1.0f / (light.constant + light.linear * dist + light.quadratic * (dist * dist));
	return vec3(spriteColour.xyz * attenuation) * light.colour;
}