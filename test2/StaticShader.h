#pragma once
#include "Light.h"
#include "Camera.h"
#include "Maths.h"

static char* VERTEX_FILE = "shaders/vertexShader.glsl";
static char* FRAGMENT_FILE = "shaders/fragmentShader.glsl";

class StaticShader : public ShaderProgram
{
private:
	int location_transformationMatrix;
	int location_projectionMatrix;
	int location_viewMatrix;
	int location_lightPosition;
	int location_lightColour;
	int location_shineDamper;
	int location_reflectivity;
	int location_useFakeLighting;
	int location_skyColour;
protected:
	void bindAttributes();
	void getAllUniformLocations();

public:
	StaticShader();
	void loadTransformationMatrix(glm::mat4);
	void loadProjectionMatrix(glm::mat4);
	void loadViewMatrix(Camera);
	void loadLight(Light light);
	void loadShineVariables(float, float);
	void loadUseFakeLightingVariable(bool);
	void loadSkyColour(float,float,float);
};
