#include "Maths.h"

glm::mat4 Maths::createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale)
{
	glm::mat4 matrix; 
	matrix = glm::translate(matrix, translation);
	matrix = glm::rotate(matrix, glm::radians(rx), glm::vec3(-1.0f, 0, 0));
	matrix = glm::rotate(matrix, glm::radians(ry), glm::vec3(0, -1.0f, 0));
	matrix = glm::rotate(matrix, glm::radians(rz), glm::vec3(0, 0, -1.0f));
	matrix = glm::scale(matrix, glm::vec3(scale,scale,scale));

	return matrix;
	
}

glm::mat4 Maths::createViewMatrix(Camera camera)
{
	glm::mat4 viewMatrix;
	viewMatrix = glm::mat4(1.0);
	//glm::rotate(viewMatrix,(float)glm::radians(camera.getPitch()), glm::vec3(1, 0, 0));
	//glm::rotate(viewMatrix, (float)glm::radians(camera.getYaw()), glm::vec3(0, 1, 0));
	glm::vec3 cameraPos = camera.getPosition();
	glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
	viewMatrix = glm::translate(viewMatrix,negativeCameraPos);
	return viewMatrix;
}
