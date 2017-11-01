#include "EntityRenderer.h"


EntityRenderer::EntityRenderer(StaticShader shader, glm::mat4 projectionMatrix)
{
	this->shader = shader;
	this->shader.start();
	this->shader.loadProjectionMatrix(projectionMatrix);
	this->shader.stop();
}




void EntityRenderer::render(std::map<TexturedModel, std::vector<Entity>> entities)
{
	for (std::map<TexturedModel, std::vector<Entity>>::iterator iter = entities.begin(); iter != entities.end(); ++iter)
	{
		TexturedModel model = iter->first;
		prepareTexturedModel(model);
		std::vector<Entity> batch = iter->second;
		for (int i = 0; i < batch.size(); i++)
		{
			prepareInstance(batch[i]);
			glDrawElements(GL_TRIANGLES, model.getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0);
		}
		unbindTexturedModel();
	}
}

void EntityRenderer::prepareTexturedModel(TexturedModel model)
{
	RawModel rawModel = model.getRawModel();
	glBindVertexArray(rawModel.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	ModelTexture texture = model.getModelTexture();
	if (texture.isGetTransparency())
	{
		disableCulling();
	}
	shader.loadUseFakeLightingVariable(texture.isFakeLighting());
	shader.loadShineVariables(texture.getShineDamper(), texture.getReflectivity());
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getID());
}

void EntityRenderer::unbindTexturedModel()
{
	enableCulling();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void EntityRenderer::prepareInstance(Entity entity)
{
	glm::mat4 transformationMatrix = Maths::createTransformationMatrix(entity.getPosition(), entity.getRotX(), entity.getRotY(), entity.getRotZ(), entity.getScale());
	shader.loadTransformationMatrix(transformationMatrix);
}



void EntityRenderer::enableCulling()
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void EntityRenderer::disableCulling()
{
	glDisable(GL_CULL_FACE);
}