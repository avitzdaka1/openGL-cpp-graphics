
//v0.03

#include "StaticShader.h"

using namespace std;


static void glfwError(int id, const char* description)
{
	std::cout << description << std::endl;
}

int main()
{
	glfwSetErrorCallback(&glfwError);

	
	if (glfwInit() == false)
	{

		fprintf(stderr, "GLFW failed to initialize!");
		return -1;
	}
	DisplayManager display = DisplayManager();

	display.createDisplay();
	 //glewExperimental=GL_TRUE;
  GLenum err=glewInit();
  if(err!=GLEW_OK)
  {
    //Problem: glewInit failed, something is seriously wrong.
    cout<<"glewInit failed, aborting."<<endl;
  }
	

	
	Loader loader = Loader();
	Renderer renderer = Renderer();
	StaticShader shader = StaticShader();

	float vertices[] =
	{
		-0.5f, 0.5f, 0,   // Left-bottom
		-0.5f, -0.5f, 0,
		0.5f, -0.5f, 0,
		0.5f, 0.5f, 0,   // Right-top
	
	};

	int indices[] = 
	{
		0,1,3,
		3,1,2
	};

	float textureCoords[] =
	{
		0,0,
		0,1,
		1,1,
		1,0
	};

	RawModel* model = loader.loadToVAO(vertices,12, textureCoords,8,indices,6);
	ModelTexture texture = ModelTexture(loader.loadTexture("res/pic1.bmp"));
	TexturedModel* texturedModel = new TexturedModel(model, texture);
	
	while (!display.checkIfWindowOpen())
	{
		renderer.prepare();
		//game logic
		shader.start();
		renderer.render(*texturedModel);
		shader.stop();
		display.updateDisplay();
		
	}

	shader.cleanUP();
	loader.cleanUP();
	display.closeDisplay();



	return 0;

}