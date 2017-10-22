#include "OBJLoader.h"
#include <sstream>


void OBJLoader::processVertex(std::vector<string> vertexData, std::vector<int> &indices, std::vector<glm::vec2> textures, std::vector<glm::vec3> normals, float textureArray[], float normalsArray[])
{
	int currentVertexPointer = std::stoi(vertexData[0], 0) - 1;
	indices.push_back(currentVertexPointer);
	glm::vec2 currentTex = textures[std::stoi(vertexData[1], 0) - 1];
	textureArray[currentVertexPointer * 2] = currentTex.x;
	textureArray[currentVertexPointer * 2+1] = 1 - currentTex.y;
	glm::vec3 currentNorm = normals[std::stoi(vertexData[2], 0) - 1];
	normalsArray[currentVertexPointer * 3] = currentNorm.x;
	normalsArray[currentVertexPointer * 3 + 1] = currentNorm.y;
	normalsArray[currentVertexPointer * 3 + 2] = currentNorm.z;
}

RawModel* OBJLoader::loadObjModel(char * fname, Loader loader)
{
	ifstream myfile;
	std::string line;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> textures;
	std::vector<glm::vec3> normals;
	std::vector<int> indices;
	float* verticesArray;
	float* normalsArray;
	float* textureArray;
	int* indicesArray;
	int elements;
	std::string* tempArray;
	std::string tempString;
	myfile.open(fname, std::ios::in);

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			std::getline(myfile, line);
			if (line[0] == 'v' && line[1] == ' ')
			{
				elements = 3;
				tempArray = new std::string[3];
				std::stringstream ssin(line);
				ssin >> tempString;
				for (int i = 0; i < elements; i++)
				{
					ssin >> tempArray[i];
				}
				glm::vec3 vertex = glm::vec3(std::stof(tempArray[0], 0), std::stof(tempArray[1], 0), std::stof(tempArray[2], 0));
				vertices.push_back(vertex);
				delete[](tempArray);

			}
			else if (line[0] == 'v' && line[1] == 't')
			{
				elements = 2;
				tempArray = new std::string[2];
				std::stringstream ssin(line);
				ssin >> tempString;
				for (int i = 0; i < elements; i++)
				{
					ssin >> tempArray[i];
				}
				glm::vec2 texture = glm::vec2(std::stof(tempArray[0], 0), std::stof(tempArray[1], 0));
				textures.push_back(texture);
				delete[](tempArray);
			}
			else if (line[0] == 'v' && line[1] == 'n')
			{
				elements = 3;
				tempArray = new std::string[3];
				std::stringstream ssin(line);
				ssin >> tempString;
				for (int i = 0; i < elements; i++)
				{
					ssin >> tempArray[i];
				}
				glm::vec3 normal = glm::vec3(std::stof(tempArray[0], 0), std::stof(tempArray[1], 0), std::stof(tempArray[2], 0));
				normals.push_back(normal);
				delete[](tempArray);
			}
			else if (line[0] == 'f')
			{
				textureArray = new float[vertices.size() * 2];
				normalsArray = new float[vertices.size() * 3];
				break;
			}


		}

		while (myfile.good())
		{
			if (!line[0] == 'f')
			{
				std::getline(myfile, line);

			}
			elements = 3;
			tempArray = new std::string[3];
			std::stringstream ssin(line);
			ssin >> tempString;
			for (int i = 0; i < elements; i++)
			{
				ssin >> tempArray[i];
			}
			std::string vertex1[3];
			std::string vertex2[3];
			std::string vertex3[3];

			int k = 0;
			for (int j = 0; j < 3; j++)
			{
				int h = 0;
				while (tempArray[0][k] != '/' && k < tempArray[0].length())
				{

					vertex1[j].append(string(1, tempArray[0][k]));
					k++;
					h++;
				}
				k++;
			}


			k = 0;
			for (int j = 0; j < 3; j++)
			{
				while (tempArray[1][k] != '/' && k < tempArray[1].length())
				{
					vertex2[j].append(string(1, tempArray[1][k]));
					k++;
				}
				k++;
			}


			k = 0;
			for (int j = 0; j < 3; j++)
			{

				while (tempArray[2][k] != '/' && k < tempArray[2].length())
				{
					vertex3[j].append(string(1, tempArray[2][k]));
					k++;
				}
				k++;
			}



			delete[](tempArray);

			std::getline(myfile, line);

			
			std::vector<std::string> myvec1(3);
			std::vector<std::string> myvec2(3);
			std::vector<std::string> myvec3(3);
			for (int i = 0; i < 3; i++)
			{
				myvec1[i] = vertex1[i];
				myvec2[i] = vertex2[i];
				myvec3[i] = vertex3[i];
			}

			processVertex(myvec1, indices, textures, normals, textureArray, normalsArray);
			processVertex(myvec2, indices, textures, normals, textureArray, normalsArray);
			processVertex(myvec3, indices, textures, normals, textureArray, normalsArray);
		}
	}
	verticesArray = new float[vertices.size() * 3];
	indicesArray = new int[indices.size()];

	int vertexPointer = 0;

	for (int i = 0; i < vertices.size(); i++)
	{
		verticesArray[vertexPointer++] = vertices[i].x;
		verticesArray[vertexPointer++] = vertices[i].y;
		verticesArray[vertexPointer++] = vertices[i].z;
	}

	for (int i = 0; i < indices.size(); i++)
		indicesArray[i] = indices[i];

	return loader.loadToVAO(verticesArray, vertices.size() * 3, textureArray, textures.size() * 2, indicesArray, indices.size());
}
