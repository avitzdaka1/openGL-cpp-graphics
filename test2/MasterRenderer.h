#pragma once
#include "StaticShader.h"
#include "EntityRenderer.h"
#include "TerrainRenderer.h"
#include "TerrainShader.h"

static const float FOV = 70;
static const float NEAR_PLANE = 0.1f;
static const float FAR_PLANE = 1000;

class MasterRenderer
{
private:
	glm::mat4 projectionMatrix;
	std::vector<Terrain> terrains;

	StaticShader shader = StaticShader();
	EntityRenderer renderer;
	TerrainRenderer terrainRenderer;
	TerrainShader terrainShader = TerrainShader();
	std::map<TexturedModel, std::vector<Entity>> entities;

public:
	MasterRenderer();
	void cleanUp();
	void render(Light, Camera);
	void processEntity(Entity);
	void prepare();
	void createProjectionMatrix();
	void processTerrain(Terrain);
	
};