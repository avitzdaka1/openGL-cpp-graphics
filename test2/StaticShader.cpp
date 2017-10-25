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
	bindAttribute(2, "normal");
}

void StaticShader::getAllUniformLocations()
{
	location_transformationMatrix = getUniformLocation("transformationMatrix");
	location_projectionMatrix = getUniformLocation("projectionMatrix");
	location_viewMatrix = getUniformLocation("viewMatrix");
	location_lightPosition = getUniformLocation("lightPosition");
	location_lightColour = getUniformLocation("lightColour");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
	loadMatrix(location_transformationMatrix, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 projection)
{
	loadMatrix(location_projectionMatrix, projection);
}

void StaticShader::loadViewMatrix(Camera camera)
{
	glm::mat4 viewMatrix = Maths::createViewMatrix(camera);
	loadMatrix(location_viewMatrix, viewMatrix);
}

void StaticShader::loadLight(Light light)
{
	loadVector(location_lightPosition, light.getPosition());
	loadVector(location_lightColour, light.getColour());
}
