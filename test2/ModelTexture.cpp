#include "ModelTexture.h"

ModelTexture::ModelTexture(int textureID)
{
	this->textureID = textureID;
}

int ModelTexture::getID()
{
	return this->textureID;
}