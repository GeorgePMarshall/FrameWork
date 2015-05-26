#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "Texture.h"

class SpriteRenderer
{
	Shader* shader;
	glm::mat4 projection;
	GLuint VAO, VBO, EBO;

public:
	//sets up array objects and buffers to draw rectangles to screen
	SpriteRenderer(int width, int height);
	~SpriteRenderer();

	//draws the texture to screen
	void DrawSprite(Texture* a_texture, GLfloat x, GLfloat y, GLfloat a_width = 0.0f, GLfloat a_height = 0.0f, GLfloat a_rotate = 0.0f, glm::vec3 a_colour = glm::vec3(1.0f));

	//operator overloads to force 16 byte allignment
	void* operator new(size_t i);
	void operator delete(void* p);

};

#endif
