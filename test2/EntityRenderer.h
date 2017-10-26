#pragma once


#include "StaticShader.h"
#include "Maths.h"



class EntityRenderer
{
private:
	StaticShader shader;

public:
	EntityRenderer(StaticShader shader, glm::mat4);
	void render(std::map<TexturedModel, std::vector<Entity>>);
	void prepareTexturedModel(TexturedModel model);

	void unbindTexturedModel();
	void prepareInstance(Entity);
};

