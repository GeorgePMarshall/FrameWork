#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(char* a_path)
{
	this->texture = new Texture(a_path);
}

AnimatedSprite::AnimatedSprite(Texture* a_texture)
{
	this->texture = a_texture;
}

AnimatedSprite::~AnimatedSprite()
{
	if (texture)
		delete texture;
}

void AnimatedSprite::Init(int a_FPS, int a_totalFrames, int a_framesPerRow, const MathLib::Vector2 &a_frameSize)
{
	this->FPS = a_FPS;
	this->totalFrames = a_totalFrames;
	this->framesPerRow = a_framesPerRow;
	this->frameSize = a_frameSize;
}

void AnimatedSprite::Update(float dt)
{
	texTransform = MathLib::Mat4();
	
	loopTime += dt * FPS;
	curFrame = (int)loopTime;

	if (curFrame >= totalFrames)
	{
		curFrame = 0.0f;
		loopTime = 0.0f;
	}

	texTransform = MathLib::translate(texTransform, MathLib::vec3((curFrame % framesPerRow) * (frameSize.x / texture->Width), (int)(curFrame / framesPerRow) * (frameSize.y / texture->Height), 1.0f));
	texTransform = MathLib::scale(texTransform, MathLib::vec3((frameSize.x / texture->Width), (frameSize.y / texture->Height), 1.0f));
}

void AnimatedSprite::Draw(SpriteRenderer* renderer, MathLib::Mat4 transform, MathLib::vec3 colour)
{
	renderer->DrawSprite(texture, transform, texTransform, colour);
}