#include "Loader.h"
#include "stb_image.h"

RawModel* Loader::loadToVAO(float positions[], int size,float textureCoords[],int texSize, int indices[], int indicesSize)
{
	GLuint vaoID = createVAO();
	bindIndicesBuffer(indices, indicesSize);
	storeDataInAttributeList(0, positions,3, size);
	storeDataInAttributeList(1, textureCoords, 2, texSize);
	unbindVAO();
	return new RawModel(vaoID, indicesSize);
}

int Loader::createVAO()
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	vaos.push_back(vaoID);
	glBindVertexArray(vaoID);
	return vaoID;
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}
void Loader::cleanUP()
{
	vaos.clear();
	vbos.clear();
	textures.clear();
}

void Loader::storeDataInAttributeList(int attributeNumber, float data[],int coordSize, int size)
{
	GLuint vboID;
	glGenBuffers(1,&vboID);
	vbos.push_back(vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, coordSize, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Loader::bindIndicesBuffer(int indices[], int size)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	vbos.push_back(vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(int), indices, GL_STATIC_DRAW);
}

int Loader::loadTexture(char* fname)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	textures.push_back(textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load(fname, &width, &height, &nrChannels, STBI_rgb);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	return textureID;
}