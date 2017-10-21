#pragma once


#include "StaticShader.h"
#include "Maths.h"

static const float FOV = 70;
static const float NEAR_PLANE = 0.1f;
static const float FAR_PLANE = 1000;

class Renderer
{
private:
	glm::mat4 projectionMatrix;
	void createProjectionMatrix();
public:
	Renderer(StaticShader shader);
	void prepare();
	void render(Entity,StaticShader);
};

