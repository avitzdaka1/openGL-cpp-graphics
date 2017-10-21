#pragma once
#include "Shader.h"
#include "Camera.h"
#include "Maths.h"

static char* VERTEX_FILE = "shaders/vertexShader.glsl";
static char* FRAGMENT_FILE = "shaders/fragmentShader.glsl";

class StaticShader : public ShaderProgram
{
private:
	int location_transformationMatrix;
	int location_projectionMatrix;
	int location_viewMatrix;
protected:
	void bindAttributes();
	void getAllUniformLocations();

public:
	StaticShader();
	void loadTransformationMatrix(glm::mat4);
	void loadProjectionMatrix(glm::mat4);
	void loadViewMatrix(Camera);
};
