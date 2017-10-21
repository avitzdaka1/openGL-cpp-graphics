#pragma once
#include "Camera.h"

class Maths
{
public:
	static glm::mat4 createTransformationMatrix(glm::vec3, float, float, float,float);
	static glm::mat4 createViewMatrix(Camera camera);
};