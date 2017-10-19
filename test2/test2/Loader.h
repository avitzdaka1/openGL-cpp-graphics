#pragma once
#include "RawModel.h"
#include "DisplayManager.h"

class Loader
{
private:
	std::vector<int> vaos;
	std::vector<int> vbos;
	std::vector<int> textures;

	int createVAO();
	void storeDataInAttributeList(int, float[],int, int);
	void unbindVAO();
	void bindIndicesBuffer(int[], int);
	
public:
	RawModel* loadToVAO(float[],int,float[],int, int[], int);
	void cleanUP();
	int loadTexture(char*);

};