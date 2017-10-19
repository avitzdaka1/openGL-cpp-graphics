#pragma once
#include "Shader.h"

static char* VERTEX_FILE = "shaders/vertexShader.glsl";
static char* FRAGMENT_FILE = "shaders/fragmentShader.glsl";

class StaticShader : public ShaderProgram
{
	

protected:
	virtual void bindAttributes();

public:
	StaticShader();

};

