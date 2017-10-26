#pragma once
#include "RawModel.h"
#include "ModelTexture.h"
#include <tuple>
class TexturedModel 
{


private:
	RawModel rawModel;
	ModelTexture texture;
	int ID;

public:
	TexturedModel(RawModel*,ModelTexture &);
	RawModel getRawModel();
	ModelTexture getModelTexture();
	bool operator<(const TexturedModel& rhs) const;
};

