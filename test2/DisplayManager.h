#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "GL\glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "GLFW\glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION


#include <vector>

using namespace std;

class DisplayManager
{
private:
	const int WIDTH = 1280;
	const int HEIGHT = 720;
	const int FPS_CAP = 60;
	GLFWwindow* window;
public:
	void createDisplay();

	void updateDisplay();

	bool checkIfWindowOpen();

	void closeDisplay();

	GLFWwindow* getWindow();
};