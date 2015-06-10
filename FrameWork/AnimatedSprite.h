#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include "Texture.h"

class AnimatedSprite : Texture
{


public:
	AnimatedSprite(char * a_path);
	~AnimatedSprite();

	void Update(float dt);



};

#endif