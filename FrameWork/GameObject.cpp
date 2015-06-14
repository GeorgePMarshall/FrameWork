#include "GameObject.h"
#include <iostream>

GameObject::GameObject() : texture(nullptr), colour(MathLib::Vector3(1.0f, 1.0f, 1.0f))
{
}


GameObject::~GameObject()
{
	delete texture;

}

void GameObject::UpdateTransform()
{
	MathLib::Mat4 translation;
	translation = MathLib::translate(translation, MathLib::vec3(position.x, position.y, 0.0f));

	MathLib::Mat4 Rotation;
	//set origin to center of object
	Rotation = MathLib::translate(Rotation, MathLib::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
	//rotate object
	Rotation = MathLib::rotate(Rotation, this->rotation, MathLib::vec3(0.0f, 0.0f, 1.0f));
	//set origin back to top left
	Rotation = MathLib::translate(Rotation, MathLib::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));

	MathLib::Mat4 scaled;
	scaled = MathLib::translate(scaled, MathLib::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
	scaled = MathLib::scale(scaled, MathLib::vec3(scale.x, scale.y, 1.0f));
	scaled = MathLib::translate(scaled, MathLib::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));


	transform = translation * Rotation * scaled;
	transform = *parentTransform * transform;
}


void GameObject::SetTexture(Texture *texture)
{
	this->texture = texture;
	
	size.x = texture->Width;
	size.y = texture->Height;

	//set default texture coords
	texTransform = MathLib::translate(texTransform, MathLib::vec3(0.0f, 0.0f, 0.0f));
	texTransform = MathLib::scale(texTransform, MathLib::vec3(1.0f, 1.0f, 0.0f));
}

void GameObject::SetTexture(AnimatedSprite *texture)
{
	this->animSprite = texture;
}

void GameObject::SetParent(GameObject &parent)
{
	parentTransform = parent.GetTransform();
}

void GameObject::SetParent(MathLib::Mat4 &parent)
{
	parentTransform = &parent;
}

MathLib::Mat4* GameObject::GetTransform()
{
	return &transform;
}

void GameObject::Update(float dt)
{
	UpdateTransform();

	if (animSprite)
		animSprite->Update(dt);

}

void GameObject::Draw(SpriteRenderer* renderer)
{
	MathLib::Mat4 scaled;
	scaled = MathLib::translate(scaled, MathLib::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
	scaled = MathLib::scale(scaled, MathLib::vec3(size.x, size.y, 1.0f));
	scaled = MathLib::translate(scaled, MathLib::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
	transform *= scaled;

	if (texture)
		renderer->DrawSprite(texture, transform, texTransform, colour);

	if (animSprite)
		animSprite->Draw(renderer, transform, colour);
}