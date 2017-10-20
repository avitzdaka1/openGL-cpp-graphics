#pragma once
#include "Entity.h"


class ShaderProgram
{
private:
	int programID;
	int vertexShaderID;
	int fragmentShaderID;

	int loadShader(const string, int);

protected:
	void loadVector(int, glm::vec3);
	void loadFloat(int, float);
	int getUniformLocation(char*);
	virtual void getAllUniformLocations() = 0;
	virtual void bindAttributes() = 0;
	void bindAttribute(int, const char*);

public:
	ShaderProgram(const char*,const char*);
	

	void start();
	void stop();
	void cleanUP();
	void loadMatrix(int, glm::mat4);

};

