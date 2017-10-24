#include "Renderer.h"

Renderer::Renderer(StaticShader shader)
{
	createProjectionMatrix();
	shader.start();
	shader.loadProjectionMatrix(projectionMatrix);
	shader.stop();
}

void Renderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	
}

void Renderer::render(Entity entity, StaticShader shader)
{
	TexturedModel model = entity.getModel();
	RawModel rawModel = model.getRawModel();
	glBindVertexArray(rawModel.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glm::mat4 transformationMatrix = Maths::createTransformationMatrix(entity.getPosition(), entity.getRotX(), entity.getRotY(), entity.getRotZ(), entity.getScale());
	
	
	shader.loadTransformationMatrix(transformationMatrix);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getID());
	glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(),GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Renderer::createProjectionMatrix()
{
	float aspectRatio = 1920 / (float)1080;
	float y_scale = (1.0f / glm::tan(glm::radians(FOV / 2.0f))) * aspectRatio;
	float x_scale = y_scale / aspectRatio;
	float frustum_length = FAR_PLANE - NEAR_PLANE;

	projectionMatrix[0][0] = x_scale;
	projectionMatrix[1][1] = y_scale;
	projectionMatrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustum_length);
	projectionMatrix[2][3] = -1;
	projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustum_length);
	projectionMatrix[3][3] = 0;
}