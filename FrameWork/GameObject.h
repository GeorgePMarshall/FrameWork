#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <MathLib\Matrix.h>
#include <MathLib\Vector.h>
#include "Texture.h"
#include "AnimatedSprite.h"
#include "SpriteRenderer.h"

class GameObject
{
	MathLib::Mat4* m_parentTransform;
	MathLib::Mat4 m_transform;
	
	Texture *m_texture;
	MathLib::Vector3 m_colour;
	MathLib::Mat4 m_texTransform;

	void UpdateTransform();

public:
	MathLib::Vector2 m_position;
	MathLib::Vector2 m_size;
	MathLib::Vector2 m_scale;
	float m_rotation;

	GameObject();
	~GameObject();

	void Update(float dt);
	void Draw(SpriteRenderer* renderer);

	MathLib::Mat4* GetTransform();
	void SetParent(GameObject &parent);
	void SetParent(MathLib::mat4 &parent);
	void SetTexture(Texture *texture);
	

};

#endif





