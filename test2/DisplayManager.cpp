#include "DisplayManager.h"

void DisplayManager::createDisplay()
{
	
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(WIDTH, HEIGHT, "My OpenGL", NULL, NULL);

	if (!window)
	{

		fprintf(stderr, " Window failed");
		glfwTerminate();
		return;
	}
	
	glfwSetWindowPos(window, 10, 30);
	glfwMakeContextCurrent(window);
	glfwSetWindowTitle(window, "New OpenGL attempt");
}

bool DisplayManager::checkIfWindowOpen()
{
	if (glfwWindowShouldClose(this->window) == false)
		return false;
	return true;
}

void DisplayManager::closeDisplay()
{
	glfwDestroyWindow(window);
}

void DisplayManager::updateDisplay()
{
	//glfwSwapInterval(-1);
	glfwSwapBuffers(window);
	glfwPollEvents();
}