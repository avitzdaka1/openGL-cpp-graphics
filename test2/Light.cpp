#include "Light.h"

Light::Light(glm::vec3 position, glm::vec3 colour)
{
	this->position = position;
	this->colour = colour;
}

void Light::setPosition(glm::vec3 position)
{
	this->position = position;
}

void Light::setColour(glm::vec3 colour)
{
	this->colour = colour;
}

glm::vec3 Light::getPosition()
{
	return this->position;
}

glm::vec3 Light::getColour()
{
	return this->colour;
}
