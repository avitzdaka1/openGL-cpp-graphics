#pragma once
#include "DisplayManager.h"



class Camera
{
private:
	glm::vec3 position;
	float pitch;
	float yaw;
	float roll;
	float speed;

public:
	Camera();
	glm::vec3 getPosition();
	float getPitch();
	float getYaw();
	float getRoll();
	
	void move(DisplayManager);
};

bool is_file_exist(const char*);
void saveCamera(Camera);
