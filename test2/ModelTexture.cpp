#include "ModelTexture.h"

ModelTexture::ModelTexture(int textureID)
{
	this->textureID = textureID;
}

void ModelTexture::setShineDamper(float shineDamper)
{
	this->shineDamper = shineDamper;
}

void ModelTexture::setReflectivity(float reflectivity)
{
	this->reflectivity = reflectivity;
}

int ModelTexture::getID()
{
	return this->textureID;
}

float ModelTexture::getShineDamper()
{
	return this->shineDamper;
}

float ModelTexture::getReflectivity()
{
	return this->reflectivity;
}
