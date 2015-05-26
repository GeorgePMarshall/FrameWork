#include "Main.h"

GLfloat x;


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
}

void Main::ProcessInput(GLfloat dt)
{
	
}

void Main::Update(GLfloat dt)
{
	
	x += dt;

}

void Main::Draw()
{
	renderer->DrawSprite(face, 300, 200 + cos(x) * 30, 200, 200);
	renderer->DrawSprite(container, 300, 300, 200, 200);
}
