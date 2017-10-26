#pragma once
#include "Light.h"
#include "Camera.h"
#include "Maths.h"

static char* TERRAIN_VERTEX_FILE = "shaders/terrainVertexShader.glsl";
static char* TERRAIN_FRAGMENT_FILE = "shaders/terrainFragmentShader.glsl";

class TerrainShader : public ShaderProgram
{
private:
	int location_transformationMatrix;
	int location_projectionMatrix;
	int location_viewMatrix;
	int location_lightPosition;
	int location_lightColour;
	int location_shineDamper;
	int location_reflectivity;
protected:
	void bindAttributes();
	void getAllUniformLocations();

public:
	TerrainShader();
	void loadTransformationMatrix(glm::mat4);
	void loadProjectionMatrix(glm::mat4);
	void loadViewMatrix(Camera);
	void loadLight(Light light);
	void loadShineVariables(float, float);
};