#pragma once
#include "Shader.h"

static char* VERTEX_FILE = "shaders/vertexShader.glsl";
static char* FRAGMENT_FILE = "shaders/fragmentShader.glsl";

class StaticShader : public ShaderProgram
{
private:
	int location_transformationMatrix;

protected:
	void bindAttributes();
	void getAllUniformLocations();

public:
	StaticShader();
	void loadTransformationMatrix(glm::mat4);

};
