#pragma once

class ModelTexture
{
private:
	int textureID;
	float shineDamper = 1;
	float reflectivity = 0;
	bool hasTransparency = false;
	bool useFakeLighting = false;
public:
	ModelTexture(int);
	void setShineDamper(float);
	void setReflectivity(float);
	void setTransparency(bool);
	void setFakeLighting(bool);

	int getID();
	float getShineDamper();
	float getReflectivity();
	bool isGetTransparency();
	bool isFakeLighting();
};