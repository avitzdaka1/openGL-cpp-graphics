#include "StaticShader.h"

StaticShader::StaticShader()
	:ShaderProgram(VERTEX_FILE, FRAGMENT_FILE)
{
	bindAttributes();
	getAllUniformLocations();
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
}

void StaticShader::getAllUniformLocations()
{
	location_transformationMatrix = getUniformLocation("transformationMatrix");

}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
	loadMatrix(location_transformationMatrix, matrix);
}