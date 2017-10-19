#pragma once


class RawModel
{
private:
	int vaoID;
	int vertexCount;
public:

	RawModel(int, int);
	int getVaoID();
	int getVertexCount();
};