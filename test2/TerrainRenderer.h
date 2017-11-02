#pragma once
#include "TerrainShader.h"
#include "Terrain.h"


class TerrainRenderer
{
private:
	TerrainShader shader;
	void prepareTerrain(Terrain terrain);
	void unbindTextureModel();
	void loadModelMatrix(Terrain terrain);
	void bindTextures(Terrain terrain);

public:
	TerrainRenderer(TerrainShader, glm::mat4);

	void render(std::vector<Terrain>);
};