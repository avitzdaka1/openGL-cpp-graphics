#include "TexturedModel.h"

TexturedModel::TexturedModel(RawModel* rawModel, ModelTexture &texture)
	:rawModel(*rawModel), texture(texture)
{
	this->ID = rawModel->getVaoID();
	this->rawModel = *rawModel;
	this->texture = texture;
}

RawModel TexturedModel::getRawModel()
{
	return this->rawModel;
}

ModelTexture TexturedModel::getModelTexture()
{
	return this->texture;
}

bool TexturedModel::operator<(const TexturedModel & rhs) const
{
	if (rhs.ID < this->ID)
		return true;
	return false;
}






