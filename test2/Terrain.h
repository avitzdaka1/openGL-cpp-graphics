#pragma once
#include "TexturedModel.h"
#include "Loader.h"
#include "TerrainTexturePack.h"

	static const float SIZE = 800.0;
	static const int VERTEX_COUNT = 128;
class Terrain
{
private: 
	float x;
	float z;
	RawModel model;
	TerrainTexturePack texturePack;
	TerrainTexture blendMap;
	RawModel* generateTerrain(Loader loader);

public:
	Terrain(int, int, Loader, TerrainTexturePack, TerrainTexture);
	float getX();
	float getZ();
	RawModel getModel();
	TerrainTexturePack getTerrainTexturePack();
	TerrainTexture getBlendMap();

};