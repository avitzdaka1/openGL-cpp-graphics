#pragma once
#include "TexturedModel.h"
#include "Loader.h"

	static const float SIZE = 800.0;
	static const int VERTEX_COUNT = 128;
class Terrain
{
private: 
	float x;
	float z;
	RawModel model;
	ModelTexture texture;
	RawModel* generateTerrain(Loader loader);

public:
	Terrain(int gridX, int gridZ, Loader loader, ModelTexture texture);
	float getX();
	float getZ();
	RawModel getModel();
	ModelTexture getTexture();

};