#pragma once

class ModelTexture
{
private:
	int textureID;
	float shineDamper = 1;
	float reflectivity = 0;
public:
	ModelTexture(int);
	void setShineDamper(float);
	void setReflectivity(float);

	int getID();
	float getShineDamper();
	float getReflectivity();
};