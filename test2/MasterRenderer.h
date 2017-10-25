#pragma once
#include "StaticShader.h"
#include "Renderer.h"

class MasterRenderer
{
private:
	StaticShader shader = StaticShader();
	Renderer renderer = Renderer(shader);;
public:
	
};