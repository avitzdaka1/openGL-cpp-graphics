#include "DisplayManager.h"

void DisplayManager::createDisplay()
{
	
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	


	this->window = glfwCreateWindow(2000, 2000, "My OpenGL", NULL, NULL);
	glfwSetWindowSize(window, 1800, 1000);
	
 	
	if (!window)
	{

		fprintf(stderr, " Window failed");
		glfwTerminate();
		return;
	}
	
	//glfwSetWindowPos(window, 10, 30);
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

GLFWwindow * DisplayManager::getWindow()
{
	return this->window;
}

milliseconds DisplayManager::getCurrentTime()
{
	milliseconds ms = duration_cast<milliseconds>(
		system_clock::now().time_since_epoch());
	return ms;
}



void DisplayManager::updateDisplay()
{
	//glfwSwapInterval(0.1);
	glfwSwapBuffers(window);
	glfwPollEvents();
}


