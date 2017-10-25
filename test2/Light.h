#pragma once

#include "Shader.h"

class Light
{
private:
	glm::vec3 position;
	glm::vec3 colour;
public:
	Light(glm::vec3, glm::vec3);
	void setPosition(glm::vec3);
	void setColour(glm::vec3);

	glm::vec3 getPosition();
	glm::vec3 getColour();
	
};