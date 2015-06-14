#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <MathLib/Matrix.h>
#include <MathLib/Vector.h>
#include <string.h>
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
	void DrawSprite(Texture* texture, GLfloat x, GLfloat y, GLfloat width = 0.0f, GLfloat height = 0.0f, GLfloat rotate = 0.0f, MathLib::vec3 colour = MathLib::vec3(1.0f, 1.0f, 1.0f));
	void DrawSprite(Texture* texture, MathLib::Vector2 position, MathLib::Vector2 size, GLfloat rotate = 0.0f, MathLib::vec3 colour = MathLib::vec3(1.0f, 1.0f, 1.0f));
	void DrawSprite(Texture* texture, MathLib::Mat4 transform, MathLib::Mat4 texCoords, MathLib::vec3 colour = MathLib::vec3(1.0f, 1.0f, 1.0f));
	
	//draws light to screen
	void DrawLight(MathLib::vec2 position, int lightID = 0, MathLib::vec3 colour = MathLib::vec3(1.0f, 1.0f, 1.0f), float constant = 1.0f, float linear = 0.0014f, float quadratic = 0.000007f);
	void DrawLight(MathLib::Mat4 *transform, int lightID = 0, MathLib::vec3 colour = MathLib::vec3(1.0f, 1.0f, 1.0f), float constant = 1.0f, float linear = 0.0014f, float quadratic = 0.000007f);

	void DestroyLight(int lightID);

	//operator overloads to force 16 byte allignment
	void* operator new(size_t i);
	void operator delete(void* p);

};

#endif
