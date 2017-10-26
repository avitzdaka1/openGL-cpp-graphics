#include "TerrainRenderer.h"

TerrainRenderer::TerrainRenderer(TerrainShader shader, glm::mat4 projectionMatrix)
{
	this->shader = shader;
	shader.start();
	shader.loadProjectionMatrix(projectionMatrix);
	shader.stop();
}

void TerrainRenderer::render(std::vector<Terrain> terrains)
{
	for (int i = 0; i < terrains.size(); i++)
	{
		prepareTerrain(terrains[i]);
		loadModelMatrix(terrains[i]);
		glDrawElements(GL_TRIANGLES, terrains[i].getModel().getVertexCount(), GL_UNSIGNED_INT, 0);

		unbindTextureModel();
	}
}

void TerrainRenderer::prepareTerrain(Terrain terrain)
{
	RawModel rawModel = terrain.getModel();
	glBindVertexArray(rawModel.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	ModelTexture texture = terrain.getTexture();
	this->shader.loadShineVariables(texture.getShineDamper(), texture.getReflectivity());
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
}

void TerrainRenderer::unbindTextureModel()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void TerrainRenderer::loadModelMatrix(Terrain terrain)
{
	glm::mat4 transformationMatrix = Maths::createTransformationMatrix(glm::vec3(terrain.getX(), 1, terrain.getZ()), 0, 0, 0, 1);
	this->shader.loadTransformationMatrix(transformationMatrix);
}