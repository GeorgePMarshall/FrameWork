#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Shader
{
public:
	//Porgram ID
	GLuint shaderProgram;

	//Reads and builds shader
	Shader(const GLchar* vertexSoucePath, const GLchar* fragmentSourcePath);

	void SetIntager(const char* a_name, GLint a_value);

	void SetMat4(const char* a_name, const glm::mat4 &a_value);

	void SetVec4(const char* a_name, const glm::vec4 &a_value);
	void SetVec3(const char* a_name, const glm::vec3 &a_value);
	void SetVec2(const char* a_name, const glm::vec2 &a_value);

	//Use the program
	void Use();

};

#endif