#include "MasterRenderer.h"

MasterRenderer::MasterRenderer()
	:renderer(shader, projectionMatrix), terrainRenderer(terrainShader, projectionMatrix)
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	createProjectionMatrix();
	this->renderer = EntityRenderer(shader, projectionMatrix);
	this->terrainRenderer = TerrainRenderer(terrainShader,projectionMatrix);
}

void MasterRenderer::cleanUp()
{
	this->shader.cleanUP();
	this->terrainShader.cleanUP();
}

void MasterRenderer::render(Light sun, Camera camera)
{
	prepare();
	this->shader.start();
	this->shader.loadLight(sun);
	this->shader.loadViewMatrix(camera);
	this->renderer.render(entities);
	this->shader.stop();
	this->terrainShader.start();
	this->terrainShader.loadLight(sun);
	this->terrainShader.loadViewMatrix(camera);
	this->terrainRenderer.render(terrains);
	this->terrainShader.stop();
	this->terrains.clear();
	this->entities.clear();
}

void MasterRenderer::createProjectionMatrix()
{
	float aspectRatio = 1920 / (float)1080;
	float y_scale = (1.0f / glm::tan(glm::radians(FOV / 2.0f))) * aspectRatio;
	float x_scale = y_scale / aspectRatio;
	float frustum_length = FAR_PLANE - NEAR_PLANE;

	projectionMatrix[0][0] = x_scale;
	projectionMatrix[1][1] = y_scale;
	projectionMatrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustum_length);
	projectionMatrix[2][3] = -1;
	projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustum_length);
	projectionMatrix[3][3] = 0;
}

void MasterRenderer::processTerrain(Terrain terrain)
{
	terrains.push_back(terrain);
}

void MasterRenderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 0, 0, 1);

}

void MasterRenderer::processEntity(Entity entity)
{
	TexturedModel entityModel = entity.getModel();
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
