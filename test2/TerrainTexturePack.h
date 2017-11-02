#pragma once
#include "TerrainTexture.h"

class TerrainTexturePack
{
private:
	TerrainTexture backgroundTexture;
	TerrainTexture rTexture;
	TerrainTexture gTexture;
	TerrainTexture bTexture;
public:
	TerrainTexturePack() {};
	TerrainTexturePack(TerrainTexture, TerrainTexture, TerrainTexture, TerrainTexture);
	TerrainTexture getBackgroundTexture();
	TerrainTexture getRTexture();
	TerrainTexture getGTexture();
	TerrainTexture getBTexture();
};