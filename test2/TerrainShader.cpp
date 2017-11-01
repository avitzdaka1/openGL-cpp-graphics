#include "TerrainShader.h"

TerrainShader::TerrainShader()
	:ShaderProgram(TERRAIN_VERTEX_FILE, TERRAIN_FRAGMENT_FILE)
{
	bindAttributes();
	getAllUniformLocations();




}

void TerrainShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
	bindAttribute(2, "normal");
}

void TerrainShader::getAllUniformLocations()
{
	location_transformationMatrix = getUniformLocation("transformationMatrix");
	location_projectionMatrix = getUniformLocation("projectionMatrix");
	location_viewMatrix = getUniformLocation("viewMatrix");
	location_lightPosition = getUniformLocation("lightPosition");
	location_lightColour = getUniformLocation("lightColour");
	location_shineDamper = getUniformLocation("shineDamper");
	location_reflectivity = getUniformLocation("reflectivity");
	location_skyColour = getUniformLocation("skyColour");
}

void TerrainShader::loadTransformationMatrix(glm::mat4 matrix)
{
	loadMatrix(location_transformationMatrix, matrix);
}

void TerrainShader::loadProjectionMatrix(glm::mat4 projection)
{
	loadMatrix(location_projectionMatrix, projection);
}

void TerrainShader::loadViewMatrix(Camera camera)
{
	glm::mat4 viewMatrix = Maths::createViewMatrix(camera);
	loadMatrix(location_viewMatrix, viewMatrix);
}

void TerrainShader::loadLight(Light light)
{
	loadVector(location_lightPosition, light.getPosition());
	loadVector(location_lightColour, light.getColour());
}

void TerrainShader::loadShineVariables(float damper, float reflectivity)
{
	loadFloat(location_shineDamper, damper);
	loadFloat(location_reflectivity, reflectivity);
}

void TerrainShader::loadSkyColour(float r, float g, float b)
{
	loadVector(location_skyColour, glm::vec3(r, g, b));
}