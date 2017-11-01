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

void ModelTexture::setTransparency(bool hasTransparency)
{
	this->hasTransparency = hasTransparency;
}

void ModelTexture::setFakeLighting(bool useFakeLighting)
{
	this->useFakeLighting = useFakeLighting;
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

bool ModelTexture::isFakeLighting()
{
	return this->useFakeLighting;
}

bool ModelTexture::isGetTransparency()
{
	return this->hasTransparency;
}
