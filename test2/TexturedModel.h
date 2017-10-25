#pragma once
#include "RawModel.h"
#include "ModelTexture.h"

class TexturedModel
{
private:
	RawModel rawModel;
	ModelTexture texture;

public:
	TexturedModel(RawModel*,ModelTexture &);
	RawModel getRawModel();
	ModelTexture getModelTexture();
};