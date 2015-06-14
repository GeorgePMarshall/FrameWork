#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <MathLib\Matrix.h>
#include <MathLib\Vector.h>
#include "Texture.h"
#include "AnimatedSprite.h"
#include "SpriteRenderer.h"

class GameObject
{
	MathLib::Mat4* parentTransform;
	MathLib::Mat4 transform;
	
	Texture* texture;
	AnimatedSprite* animSprite;
	MathLib::Vector3 colour;
	MathLib::Mat4 texTransform;

	void UpdateTransform();

public:
	MathLib::Vector2 position;
	MathLib::Vector2 size;
	MathLib::Vector2 scale = MathLib::Vector2(1.0f, 1.0f);
	float rotation;

	GameObject();
	~GameObject();

	void Update(float dt);
	void Draw(SpriteRenderer* renderer);

	MathLib::Mat4* GetTransform();
	void SetParent(GameObject &parent);
	void SetParent(MathLib::mat4 &parent);
	void SetTexture(Texture *texture);
	void SetTexture(AnimatedSprite *texture);
	

};

#endif





