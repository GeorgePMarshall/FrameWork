#include "Main.h"

float speed = 200.0f;
float time;

Main::Main(GLuint a_width, GLuint a_height) : width(a_width), height(a_height) {}

Main::~Main()
{
	delete renderer;
	delete face;
	delete container;
	delete animation;
}

void Main::Init()
{
	//create sprite renderer
	renderer = new SpriteRenderer(width, height);

	//create textures
	face = new Texture("awesomeface.png");
	container = new Texture("container.jpg");
	animation = new AnimatedSprite("wizard.png");

	//initialize animated textures
	animation->Init(4, 24, 12, MathLib::vec2(32, 32));

	//set game object textures
	playerRoot.SetTexture(animation);
	player1.SetTexture(face);
	player2.SetTexture(face);

	//set game object parents
	playerRoot.SetParent(rootNode);
	player1.SetParent(playerRoot);
	player2.SetParent(playerRoot);

	//set game objects positions relative to parents
	playerRoot.position = MathLib::Vector2(width/2, height/2);
	playerRoot.size = MathLib::Vector2(100, 100);

	player1.position = MathLib::Vector2(-100, 0);
	player1.size = MathLib::Vector2(100, 100);

	player2.position = MathLib::Vector2(100, 0);
	player2.size = MathLib::Vector2(100, 100);
}

void Main::ProcessInput(GLfloat dt)
{
	playerRoot.position.x += speed * dt * Keys[GLFW_KEY_RIGHT];
	playerRoot.position.x -= speed * dt * Keys[GLFW_KEY_LEFT];
	playerRoot.position.y -= speed * dt * Keys[GLFW_KEY_UP];
	playerRoot.position.y += speed * dt * Keys[GLFW_KEY_DOWN];
}

void Main::Update(GLfloat dt)
{
	playerRoot.rotation += dt * 100;
	time += dt;
	player1.position.x = -200 - sin(time) * 100;
	player2.position.x = 200 + sin(time) * 100;
	
	//Update game objects
	playerRoot.Update(dt);
	player1.Update(dt);
	player2.Update(dt);
}

void Main::Draw()
{
	//Draw Lights
	if ((int)time % 7 < 3)
		renderer->DestroyLight(0);
	else
		renderer->DrawLight(player1.GetTransform(), 0, MathLib::vec3(1.0f, 0.0f, 0.0f), 1.0);
	
	if ((int)time % 4 < 2)
		renderer->DestroyLight(1);
	else
		renderer->DrawLight(player2.GetTransform(), 1, MathLib::vec3(0.0f, 1.0f, 0.0f), 1.0);

	if ((int)time % 5 < 2)
		renderer->DestroyLight(2);
	else
		renderer->DrawLight(playerRoot.GetTransform(), 2, MathLib::vec3(0.0f, 0.0f, 1.0f), 0.7);

	//Draw textures
	renderer->DrawSprite(container, 0, 0, width, height);

	//Draw Game Objects
	playerRoot.Draw(renderer);
	player1.Draw(renderer);
	player2.Draw(renderer);
}
