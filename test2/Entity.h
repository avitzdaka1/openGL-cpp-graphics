#pragma once
#include "TexturedModel.h"
#include "DisplayManager.h"

class Entity
{
private:
	TexturedModel model;
	glm::vec3 position;
	float rotX, rotY, rotZ;
	float scale;

public:
	Entity(TexturedModel, glm::vec3, float, float, float, float);
	void setModel(TexturedModel);
	void setPosition(glm::vec3);
	void setRotX(float);
	void setRotY(float);
	void setRotZ(float);
	void setScale(float);
	void increasePosition(float, float, float);
	void increaseRotation(float, float, float);

	TexturedModel getModel();
	glm::vec3 getPosition();
	float getRotX();
	float getRotY();
	float getRotZ();
	float getScale();
};

