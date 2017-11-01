#pragma once
#include "StaticShader.h"
#include "EntityRenderer.h"
#include "TerrainRenderer.h"
#include "TerrainShader.h"

static const float FOV = 70;
static const float NEAR_PLANE = 0.1f;
static const float FAR_PLANE = 10000;
static const float RED = 0.5f;
static const float GREEN = 0.5f;
static const float BLUE = 0.5f;

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