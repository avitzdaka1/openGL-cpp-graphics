#include "Maths.h"

glm::mat4 Maths::createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale)
{
	glm::mat4 matrix; 
	glm::translate(matrix, translation);
	glm::rotate(matrix, glm::radians(rx), glm::vec3(-1.0f, 0, 0));
	glm::rotate(matrix, glm::radians(ry), glm::vec3(0, -1.0f, 0));
	glm::rotate(matrix, glm::radians(rz), glm::vec3(0, 0, -1.0f));
	glm::scale(matrix, glm::vec3(0.5f));

	return matrix;
	
}