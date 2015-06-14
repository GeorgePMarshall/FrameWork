#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include "Texture.h"
#include "SpriteRenderer.h"
#include <MathLib\Matrix.h>
#include <MathLib\Vector.h>

class AnimatedSprite 
{
	Texture* texture;
	MathLib::Mat4 texTransform;

	MathLib::Vector2 frameSize;

	int FPS = 12;
	int totalFrames = 1;
	int framesPerRow = 1;

	float loopTime = 0;
	int curFrame = 0;

public:
	AnimatedSprite(char* a_path);
	AnimatedSprite(Texture* texture);
	~AnimatedSprite();

	void Init(int FPS, int totalFrames, int framesPerRow, const MathLib::Vector2 &frameSize);

	void Update(float dt);
	void Draw(SpriteRenderer* renderer, MathLib::Mat4 transform, MathLib::vec3 colour);
};

#endif