#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(int width, int height)
{
	//create shader
	shader = new Shader("VertexShader.shader", "FragmentShader.shader");

	//set orthographic projection matrix
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(width), static_cast<GLfloat>(height), 0.0f, -1.0f, 1.0f);

	shader->SetIntager("inTexture", 0);
	shader->SetMat4("projection", projection);

	//array of verticies for our rectangle
	GLfloat verticies[] =
	{   //position		//texture UVs
		0.0f, 1.0f,		0.0f, 1.0f, 
		1.0f, 1.0f,		1.0f, 1.0f, 
		1.0f, 0.0f,		1.0f, 0.0f, 
		0.0f, 0.0f,		0.0f, 0.0f	
	};


	//tell it how to draw a rectangle
	GLuint indices[] =
	{
		0, 1, 3,
		1, 2, 3
	};

	glGenVertexArrays(1, &this->VAO);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	//bind VAO 
	glBindVertexArray(VAO);

	//bind our buffer to array buffer target
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//copy vertex data into buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	//bind our element buffer to element array buffer target
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//copy indecies data into element buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//enable the ertex atributes
	glEnableVertexAttribArray(0);
	//set how to interpret the vertex data
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);

	//enable the ertex atributes
	glEnableVertexAttribArray(1);
	//set how to interpret the texture data
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));

	//bind VAO 
	glBindVertexArray(0);


}


SpriteRenderer::~SpriteRenderer()
{
	delete shader;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
float j;

void SpriteRenderer::DrawSprite(Texture* a_texture, GLfloat x, GLfloat y, GLfloat a_width, GLfloat a_height, GLfloat a_rotate, glm::vec3 a_colour)
{
	//set shader to use
	this->shader->Use();

	//create model matrix
	glm::mat4 model;

	//set model matrix to current draw position
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	
	//set origin to center of object
	model = glm::translate(model, glm::vec3(0.5f * a_width, 0.5 * a_height, 0.0f));
	//rotate object
	model = glm::rotate(model, glm::radians(a_rotate), glm::vec3(0.0f, 0.0f, 1.0f));
	//set origin back to top left
	model = glm::translate(model, glm::vec3(-0.5f * a_width, -0.5 * a_height, 0.0f));
	
	//scale object
	model = glm::scale(model, glm::vec3(a_width, a_height, 1.0f));


	//create texture UV matrix
	glm::mat4 texUV;

	//translate and scale texture coordinates
	texUV = glm::translate(texUV, glm::vec3(0.0, 0.0, 0.0));
	texUV = glm::scale(texUV, glm::vec3(1.0, 1.0, 0.0));

	 //pass transform matrixes and sprite colour to shaders
	this->shader->SetMat4("model", model);	
	this->shader->SetMat4("texSource", texUV);
	this->shader->SetVec3("spriteColour", a_colour);


	//binds default texture unit
	glActiveTexture(GL_TEXTURE0);
	//bind texture to active unit
	a_texture->Bind();
	

	//draw
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


}

void* SpriteRenderer::operator new(size_t i)
{
	return _aligned_malloc(i, 16);
}

void SpriteRenderer::operator delete(void* p)
{
	return _aligned_free(p);
}