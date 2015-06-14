#include "Shader.h"

Shader::Shader(const GLchar* vertexSoucePath, const GLchar* fragmentSourcePath)
{
	string vertexShaderSource;
	string fragmentShaderSource;

	try
	{
		//open files
		ifstream vShaderFile(vertexSoucePath);
		ifstream fShaderFile(fragmentSourcePath);
		stringstream vShaderStream, fShaderStream;

		//read shader contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		//close files
		vShaderFile.close();
		fShaderFile.close();

		//convert to character array
		vertexShaderSource = vShaderStream.str();
		fragmentShaderSource = fShaderStream.str();
	}
	catch (exception e)
	{
		cout << "Shader files not sucsessfuly read" << endl;
	}

	fragmentShaderSource.insert(17, "\n#define NUM_OF_LIGHTS " + std::to_string(NUM_OF_LIGHTS) + "\n");

	//create a vertex shader
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//read in the shader source code as a string then compile
	const GLchar* vSource = vertexShaderSource.c_str();
	glShaderSource(vertexShader, 1, &vSource, NULL);
	glCompileShader(vertexShader);

	//check if vertex shader complaition was successful
	GLint vertexSuccess;
	GLchar vertexInfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);
	if (!vertexSuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, vertexInfoLog);
		std::cout << "Vertex shader complaition failed\n" << vertexInfoLog << std::endl;
	}

	//create a fragment shader
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	//read in the shader source code as a string then compile
	const GLchar* fSource = fragmentShaderSource.c_str();
	glShaderSource(fragmentShader, 1, &fSource, NULL);
	glCompileShader(fragmentShader);

	//check if fragment shader complaition was successful
	GLint fragmentSuccess;
	GLchar fragmentInfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &fragmentSuccess);
	if (!fragmentSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentInfoLog);
		std::cout << "Fragment shader complaition failed\n" << fragmentInfoLog << std::endl;
	}

	//create shader program
	this->shaderProgram = glCreateProgram();

	//attach shaders the the program and then link them together 
	glAttachShader(this->shaderProgram, vertexShader);
	glAttachShader(this->shaderProgram, fragmentShader);
	glLinkProgram(this->shaderProgram);

	//check if fragment shader program linking was successful
	GLint shaderProgramSuccess;
	GLchar shaderProgramInfoLog[512];
	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &shaderProgramSuccess);
	if (!shaderProgramSuccess)
	{
		glGetProgramInfoLog(this->shaderProgram, 512, NULL, shaderProgramInfoLog);
		std::cout << "shader program creation/linking failed\n" << shaderProgramInfoLog << std::endl;
	}


	//deletes shaders as they are now in the shader programs
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Use()
{
	glUseProgram(this->shaderProgram);
}

void Shader::SetIntager(const char* a_name, GLint a_value)
{
	this->Use();
	glUniform1i(glGetUniformLocation(this->shaderProgram, a_name), a_value);
}

void Shader::SetMat4(const char* a_name, MathLib::mat4 &a_value)
{
	this->Use();
	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, a_name), 1, GL_TRUE, a_value.GetArray());
}

void Shader::SetVec4(const char* a_name, const MathLib::vec4 &a_value)
{
	this->Use();
	glUniform4f(glGetUniformLocation(this->shaderProgram, a_name), a_value.x, a_value.y, a_value.z, a_value.w);
}

void Shader::SetVec3(const char* a_name, const MathLib::vec3 &a_value)
{
	this->Use();
	glUniform3f(glGetUniformLocation(this->shaderProgram, a_name), a_value.x, a_value.y, a_value.z);
}

void Shader::SetVec2(const char* a_name, const MathLib::vec2 &a_value)
{
	this->Use();
	glUniform2f(glGetUniformLocation(this->shaderProgram, a_name), a_value.x, a_value.y);
}

void Shader::SetFloat(const char* a_name, const float &a_value)
{
	this->Use();
	glUniform1f(glGetUniformLocation(this->shaderProgram, a_name), a_value);
}
