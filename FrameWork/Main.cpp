#include "Main.h"

GLfloat x = 0.0f, y = 0.0f, speed = 200.0f, movel = 0.0f;

MathLib::Vector2 position;

Main::Main(GLuint a_width, GLuint a_height) : width(a_width), height(a_height)
{

}


Main::~Main()
{
	delete renderer;
	delete face;
	delete container;
}

void Main::Init()
{
	face = new Texture("awesomeface.png");
	container = new Texture("container.jpg");
	renderer = new SpriteRenderer(width, height);

	player1.SetTexture(face);
	player2.SetTexture(face);

	player1.SetParent(rootNode);
	player2.SetParent(player1);

	player1.m_position.x = 100;
	player1.m_position.y = 100;
	player1.m_scale.x = 1;
	player1.m_scale.y = 1;
	player1.m_size.x = 100;
	player1.m_size.y = 100;

	player2.m_position.x = 100;
	player2.m_position.y = 100;
	player2.m_scale.x = 1;
	player2.m_scale.y = 1;
	player2.m_size.x = 100;
	player2.m_size.y = 100;

}

void Main::ProcessInput(GLfloat dt)
{
	player1.m_position.x += speed * dt * Keys[GLFW_KEY_RIGHT];
	player1.m_position.x -= speed * dt * Keys[GLFW_KEY_LEFT];
	player1.m_position.y -= speed * dt * Keys[GLFW_KEY_UP];
	player1.m_position.y += speed * dt * Keys[GLFW_KEY_DOWN];
}

void Main::Update(GLfloat dt)
{
	player1.m_rotation += dt * 10;
	player1.Update(dt);
	player2.Update(dt);
}

void Main::Draw()
{
	MathLib::Vector4 temp(1,1,1,1);
	temp = *player2.GetTransform() * temp;

	renderer->DrawLight(player1.m_position.x + 50, player1.m_position.y + 50);
	renderer->DrawLight2(temp.x, temp.y);
	renderer->DrawSprite(container, 0, 0, width, height);
	//renderer->DrawSprite(face, 0, 0, 100, 100);
	player1.Draw(renderer);
	player2.Draw(renderer);

}
