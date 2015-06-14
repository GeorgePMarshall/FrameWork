#ifndef SHADER_H
#define SHADER_H

#define NUM_OF_LIGHTS 10

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <MathLib\Matrix.h>
#include <MathLib\Vector.h>

using namespace std;

class Shader
{
public:
	//Porgram ID
	GLuint shaderProgram;

	//Reads and builds shader
	Shader(const GLchar* vertexSoucePath, const GLchar* fragmentSourcePath);

	void SetIntager(const char* a_name, GLint a_value);

	void SetMat4(const char* a_name, MathLib::mat4 &a_value);

	void SetVec4(const char* a_name, const MathLib::vec4 &a_value);
	void SetVec3(const char* a_name, const MathLib::vec3 &a_value);
	void SetVec2(const char* a_name, const MathLib::vec2 &a_value);
	void SetFloat(const char* a_name, const float &a_value);


	//Use the program
	void Use();

};

#endif