//GELW
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW
#include <GLFW/glfw3.h>
//IO Stream
#include <iostream>
//Shader Class
#include "Shader.h"
//SOIL for loading images
#include <SOIL/SOIL.h>
//GLM math lib for matricies
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Main.h"

//declare key callback func
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

void ScreenResizeCallback(GLFWwindow* window, int width, int height);

//starting Screen Resolution
const GLuint WIDTH = 1200, HEIGHT = 720;

GLboolean showFps = GL_TRUE;
GLboolean vSync = GL_TRUE;

Main *game;

int main()
{
	//initialize glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 16);

	//Create Window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL MotherFuckers", nullptr, nullptr); //glfwGetPrimaryMonitor(), nullptr);
	glfwMakeContextCurrent(window);
	if (window == NULL)
	{
		std::cout << "Failed to Create Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to Initialize GLEW" << std::endl;
		return -1;
	}

	//OpenGL configuration
	glViewport(0, 0, WIDTH, HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_MULTISAMPLE);
	glfwSwapInterval(vSync); //v-sync leave on or gpu noise

	//Set callbacks
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetFramebufferSizeCallback(window, ScreenResizeCallback);

	//initialize game
	game = new Main(WIDTH, HEIGHT);
	game->Init();
	game->state = GAME_RUNNING;

	//for detaTime
	GLfloat deltaTime = 0.0f, lastFrame = 0.0f, currentFrame;

	//for fps
	GLfloat timeElapsed = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		//Calculate delta time
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//calculate and display fps
		if (showFps)
		{
			timeElapsed += deltaTime;
			if (timeElapsed > 0.1f)
			{
				std::cout << (int)(1.0f / deltaTime) << std::endl;
				timeElapsed -= 0.1;
			}
		}	
			
		//poll glfw events
		glfwPollEvents();

		//process usern input
		game->ProcessInput(deltaTime);

		//update game
		game->Update(deltaTime);
		
		//Clear then Draw
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		game->Draw();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

//called when key is pressed
void KeyCallback(GLFWwindow* a_window, int a_key, int a_scancode, int a_action, int a_mode)
{
	//if Escape pressed set windowShouldClose to true closing the application 
	if (a_key == GLFW_KEY_ESCAPE && a_action == GLFW_PRESS)
		glfwSetWindowShouldClose(a_window, GL_TRUE);


	if (a_key >= 0 && a_key < 1024)
	{
		if (a_action == GLFW_PRESS)
			game->Keys[a_key] = true;
		else if (a_action == GLFW_RELEASE)
			game->Keys[a_key] = false;

		
	}
}

//called when screen resized
void ScreenResizeCallback(GLFWwindow* a_window, int a_width, int a_height)
{
	glViewport(0, 0, a_width, a_height);
}