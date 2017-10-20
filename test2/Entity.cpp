#include "Entity.h"

Entity::Entity(TexturedModel model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale)
	:model(model)
{
	this->model = model;
	this->position = position;
	this->rotX = rotX;
	this->rotY = rotY;
	this->rotZ = rotZ;
	this->scale = scale;
}

void Entity::setModel(TexturedModel model)
{
	this->model = model;
}
void Entity::setPosition(glm::vec3 position)
{
	this->position = position;
}
void Entity::setRotX(float rotX)
{
	this->rotX = rotX;
}
void Entity::setRotY(float rotY)
{
	this->rotY = rotY;
}
void Entity::setRotZ(float rotZ)
{
	this->rotZ = rotZ;
}
void Entity::setScale(float scale)
{
	this->scale = scale;
}

void Entity::increasePosition(float dx, float dy, float dz)
{
	this->position.x += dx;
	this->position.y += dy;
	this->position.z += dz;
}

void Entity::increaseRotation(float dx, float dy, float dz)
{
	this->rotX += dx;
	this->rotY += dy;
	this->rotZ += dz;
}


TexturedModel Entity::getModel()
{
	return this->model;
}
glm::vec3 Entity::getPosition()
{
	return this->position;
}
float Entity::getRotX()
{
	return this->rotX;
}
float Entity::getRotY()
{
	return this->rotY;
}
float Entity::getRotZ()
{
	return this->rotZ;
}
float Entity::getScale()
{
	return this->scale;
}