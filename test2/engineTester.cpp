
//v0.13

#include "MasterRenderer.h"
#include "OBJLoader.h"
#include <time.h>

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
	
	RawModel* model = OBJLoader::loadObjModel("res/dragon.myobject",loader);
	RawModel* model2 = OBJLoader::loadObjModel("res/stall.myobject", loader);
	
	ModelTexture* texture = new ModelTexture(loader.loadTexture("res/dragon.png"));
	ModelTexture* texture2 = new ModelTexture(loader.loadTexture("res/stall.bmp"));
	ModelTexture* terrTexture = new ModelTexture(loader.loadTexture("res/grass.jpg"));
	ModelTexture* terrTexture2 = new ModelTexture(loader.loadTexture("res/water.jpg"));
	texture->setShineDamper(10);
	texture->setReflectivity(1);
	
	TexturedModel* texturedModel = new TexturedModel(model, *texture );
	TexturedModel* texturedModel2 = new TexturedModel(model2, *texture2);

	//Entity entity = Entity(*texturedModel,glm::vec3(0,-5,-50),0.0f,0.0f,0.0f,1.0f);

	std::vector<Entity> allModels;
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		float x = rand() % 10 *10 *pow(-1,i);
		float y = rand() % 10  * (-1);
		float z = rand() % 10 * -30;
		Entity temp = Entity(*texturedModel, glm::vec3(x, y, z), 0, rand() % 10, 0, 1);
		Entity temp2 = Entity(*texturedModel2, glm::vec3(x, y, z), 0, rand() % 10, 0, 1);
		allModels.push_back(temp);
		allModels.push_back(temp2);
	}

	Light light = Light(glm::vec3(0, -30, 0),glm::vec3(1,1,1));
	Terrain terrain = Terrain(0,0,loader, *terrTexture);
	Terrain terrain2 = Terrain(1, 0, loader, *terrTexture2);

	Camera camera = Camera();
	
	TexturedModel*  t = new TexturedModel(model, terrain2.getTexture());
	Entity temp = Entity(*t, glm::vec3(0, 0, 0), 0, -2, 0, 1);

	double lastTime = glfwGetTime();
	int nbFrames = 0;
	MasterRenderer renderer = MasterRenderer();
	while (!display.checkIfWindowOpen())
	{

		
		double currentTime = glfwGetTime();
		nbFrames++;
		if (currentTime - lastTime >= 1.0) {
			printf("%f ms/frame   fps:  %f \n", 1000.0 / double(nbFrames), (float)nbFrames);             // Print spf and fps to console.
			nbFrames = 0;
			lastTime += 1.0;
		}



		for (int i = 0; i < 200; i++)
			allModels[i].increaseRotation(0, 2, 0);																	// Rotate objects.
		camera.move(display);
		
		//game logic
		
	//	renderer.processTerrain(terrain);
	//	renderer.processTerrain(terrain2);
		//for (int i = 0; i < 200; i++)
		//	renderer.processEntity(allModels[i]);																	// Process each object.
		renderer.processEntity(temp);
		renderer.render(light,camera);
		display.updateDisplay();
		
	}
	renderer.cleanUp();
	loader.cleanUP();
	display.closeDisplay();



	return 0;

}