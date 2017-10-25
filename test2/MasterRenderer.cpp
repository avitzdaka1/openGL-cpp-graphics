#include "MasterRenderer.h"

void MasterRenderer::cleanUp()
{
	this->shader.cleanUP();
}

void MasterRenderer::render(Light sun, Camera camera)
{
	this->renderer.prepare();
	this->shader.start();
	this->shader.loadLight(sun);
	this->shader.loadViewMatrix(camera);
	this->renderer.render(entities);
	this->shader.stop();
	this->entities.clear();
}

void MasterRenderer::processEntity(Entity entity)
{
	TexturedModel entityModel = entity.getModel();
	//std::map<TexturedModel, std::vector<Entity>>::iterator it = entities.find(entityModel);
	std::vector<Entity> *batch = &entities[entityModel];//it->second;
	if (!batch->empty())
		batch->push_back(entity);
		else
		{
		std::vector<Entity> newBatch;
		newBatch.push_back(entity);
		entities[entityModel] = newBatch;


		
		
		
		






		}
}
