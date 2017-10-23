#include "Camera.h"

Camera::Camera()
{
	
}

glm::vec3 Camera::getPosition()
{
	return this->position;
}

float Camera::getPitch()
{
	return this->pitch;
}

float Camera::getYaw()
{
	return this->yaw;
}

float Camera::getRoll()
{
	return this->roll;
}

void Camera::move(DisplayManager display)
{
	if (glfwGetKey(display.getWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		position.z -= 0.02f;
	}

	if (glfwGetKey(display.getWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		position.x += 0.02f;
	}

	if (glfwGetKey(display.getWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		position.x -= 0.02f;
	}

	if (glfwGetKey(display.getWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		position.z += 0.02f;
	}
}
