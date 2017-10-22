
//v0.08

#include "Renderer.h"
#include "OBJLoader.h"


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
	StaticShader shader = StaticShader();
	Renderer renderer = Renderer(shader);
	/*
	float vertices[] = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f

	};

	float textureCoords[] = {

		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0


	};

	int indices[] = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22

	};
	*/
	RawModel* model = OBJLoader::loadObjModel("res/stall.obj", loader);
	ModelTexture texture = ModelTexture(loader.loadTexture("res/stall.png"));
	TexturedModel* texturedModel = new TexturedModel(model, texture);
	Entity entity = Entity(*texturedModel,glm::vec3(0,0,-50),0.0f,0.0f,0.0f,1.0f);
	
	Camera camera = Camera();

	//OBJLoader a;
	//a.loadObjModel("res/stall.obj", loader);


	while (!display.checkIfWindowOpen())
	{
		entity.increaseRotation(0, 1, 0);
		camera.move(display);
		renderer.prepare();
		//game logic
		shader.start();
		shader.loadViewMatrix(camera);
		renderer.render(entity,shader);
		shader.stop();
		display.updateDisplay();
		
	}

	shader.cleanUP();
	loader.cleanUP();
	display.closeDisplay();



	return 0;

}