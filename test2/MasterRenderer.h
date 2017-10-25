#pragma once
#include "StaticShader.h"
#include "Renderer.h"


class MasterRenderer
{
private:
	StaticShader shader = StaticShader();
	Renderer renderer = Renderer(shader);
	std::map<TexturedModel, std::vector<Entity>> entities;
public:
	
	void cleanUp();
	void render(Light, Camera);
	void processEntity(Entity);

	
};