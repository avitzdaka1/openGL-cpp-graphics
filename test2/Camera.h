#pragma once
#include "DisplayManager.h"



class Camera
{
private:
	glm::vec3 position;
	float pitch;
	float yaw;
	float roll;

public:
	Camera();
	glm::vec3 getPosition();
	float getPitch();
	float getYaw();
	float getRoll();
	
	void move(DisplayManager);
};