#pragma once


#include "StaticShader.h"
#include "Maths.h"

class Renderer
{
public:
	void prepare();
	void render(Entity,StaticShader);
};

