#ifndef MAIN_H
#define MAIN_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SpriteRenderer.h"
#include "Texture.h"
#include <MathLib\Vector.h>
#include <MathLib\Matrix.h>
#include "GameObject.h"

enum GameState
{
	GAME_RUNNING,
	GAME_OTHER
};


class Main
{
	MathLib::Mat4 rootNode;
	SpriteRenderer* renderer;
	Texture* face;
	Texture* container;
	AnimatedSprite* animation;
	GameObject playerRoot;
	GameObject player1;
	GameObject player2;


	GLuint width, height;

public:

	GameState state;
	bool Keys[1024];

	Main(GLuint width, GLuint height);
	~Main();

	void Init();
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Draw();

};

#endif
