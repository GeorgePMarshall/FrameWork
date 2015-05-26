#ifndef MAIN_H
#define MAIN_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SpriteRenderer.h"
#include "Texture.h"

enum GameState
{
	GAME_RUNNING,
	GAME_OTHER
};


class Main
{
	SpriteRenderer* renderer;
	Texture* face;
	Texture* container;

	const GLuint width, height;

public:

	GameState state;
	GLboolean Keys[1024];

	Main(GLuint width, GLuint height);
	~Main();

	void Init();
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Draw();

};

#endif
