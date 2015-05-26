#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>
#include <SOIL/SOIL.h>

class Texture
{
public:

	//ID of the texture object
	GLuint ID;

	//Width and height demensions of the texture
	int Width, Height;

	//image Formats
	GLuint Image_Format, Internal_Format;

	//Texure Config
	GLuint Wrap_S, Wrap_T, Filter_Min, Filter_Max;

	//constructor loads and creates new texture
	Texture(const char * a_path, const bool alpha = true);

	//Binds the texture as the current active GL_TEXTURE_2D
	void Bind() const;
	
};

#endif