#include "GameObject.h"
#include <iostream>

GameObject::GameObject() : m_texture(nullptr), m_colour(MathLib::Vector3(1.0f, 1.0f, 1.0f))
{
}


GameObject::~GameObject()
{
	delete m_texture;

}

void GameObject::UpdateTransform()
{
	MathLib::Mat4 translation;
	translation = MathLib::translate(translation, MathLib::vec3(m_position.x, m_position.y, 0.0f));

	MathLib::Mat4 Rotation;
	//set origin to center of object
	Rotation = MathLib::translate(Rotation, MathLib::vec3(0.5f * m_scale.x, 0.5f * m_scale.y, 0.0f));
	//rotate object
	Rotation = MathLib::rotate(Rotation, m_rotation, MathLib::vec3(0.0f, 0.0f, 1.0f));
	//set origin back to top left
	Rotation = MathLib::translate(Rotation, MathLib::vec3(-0.5f * m_scale.x, -0.5f * m_scale.y, 0.0f));

	MathLib::Mat4 scaled;
	scaled = MathLib::translate(scaled, MathLib::vec3(0.5f * m_scale.x, 0.5f * m_scale.y, 0.0f));
	scaled = MathLib::scale(scaled, MathLib::vec3(m_scale.x, m_scale.y, 1.0f));
	scaled = MathLib::translate(scaled, MathLib::vec3(-0.5f * m_scale.x, -0.5f * m_scale.y, 0.0f));


	m_transform = translation * Rotation * scaled;
	m_transform = *m_parentTransform * m_transform;
}


void GameObject::SetTexture(Texture *texture)
{
	m_texture = texture;
	
	m_size.x = m_texture->Width;
	m_size.y = m_texture->Height;

	//set default texture coords
	m_texTransform = MathLib::translate(m_texTransform, MathLib::vec3(0.0, 0.0, 0.0));
	m_texTransform = MathLib::scale(m_texTransform, MathLib::vec3(1.0, 1.0, 0.0));
}

void GameObject::SetParent(GameObject &parent)
{
	m_parentTransform = parent.GetTransform();
}

void GameObject::SetParent(MathLib::Mat4 &parent)
{
	m_parentTransform = &parent;
}

MathLib::Mat4* GameObject::GetTransform()
{
	return &m_transform;
}

void GameObject::Update(float dt)
{
	UpdateTransform();
}

void GameObject::Draw(SpriteRenderer* renderer)
{
	MathLib::Mat4 scaled;
	scaled = MathLib::translate(scaled, MathLib::vec3(0.5f * m_scale.x, 0.5f * m_scale.y, 0.0f));
	scaled = MathLib::scale(scaled, MathLib::vec3(m_size.x, m_size.y, 1.0f));
	scaled = MathLib::translate(scaled, MathLib::vec3(-0.5f * m_scale.x, -0.5f * m_scale.y, 0.0f));
	m_transform *= scaled;

	if (m_texture)
		renderer->DrawSpriteMat4(m_texture, m_transform, m_texTransform, m_colour);
}