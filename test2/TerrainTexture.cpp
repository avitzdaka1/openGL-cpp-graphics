#include "TerrainTexture.h"

TerrainTexture::TerrainTexture(int textureID)
{
	this->textureID = textureID;
}


int TerrainTexture::getTextureID()
{
	return this->textureID;
}
