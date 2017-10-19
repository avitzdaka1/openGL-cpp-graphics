#pragma once

#include "Loader.h"
#include "TexturedModel.h"

class Renderer
{
public:
	void prepare();
	void render(TexturedModel &);
};

