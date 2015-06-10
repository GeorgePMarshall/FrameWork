#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <MathLib/Matrix.h>
#include <MathLib/Vector.h>
#include "Shader.h"
#include "Texture.h"


class SpriteRenderer
{
	Shader* shader;
	MathLib::mat4 projection;
	GLuint VAO, VBO, EBO;

public:
	//sets up array objects and buffers to draw rectangles to screen
	SpriteRenderer(int width, int height);
	~SpriteRenderer();

	//draws the texture to screen
	void DrawSprite(Texture* a_texture, GLfloat x, GLfloat y, GLfloat a_width = 0.0f, GLfloat a_height = 0.0f, GLfloat a_rotate = 0.0f, MathLib::vec3 a_colour = MathLib::vec3(1.0f, 1.0f, 1.0f));
	void DrawSpriteMat4(Texture* a_texture, MathLib::Mat4, MathLib::Mat4, MathLib::vec3 a_colour = MathLib::vec3(1.0f, 1.0f, 1.0f));
	void DrawLight(GLfloat x, GLfloat y);
	void DrawLight2(GLfloat x, GLfloat y);

	//operator overloads to force 16 byte allignment
	void* operator new(size_t i);
	void operator delete(void* p);

};

#endif
