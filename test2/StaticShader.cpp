#include "StaticShader.h"

StaticShader::StaticShader()
	:ShaderProgram(VERTEX_FILE, FRAGMENT_FILE)
{
	bindAttributes();
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
}