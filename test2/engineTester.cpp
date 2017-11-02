
//v0.18

#include "MasterRenderer.h"
#include "OBJLoader.h"
#include <time.h>
#include "TerrainTexturePack.h"

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
	
	RawModel* dragon = OBJLoader::loadObjModel("res/dragon.myobject",loader);				// Entity objects
	RawModel* stall = OBJLoader::loadObjModel("res/stall.myobject", loader);
	RawModel* plant = OBJLoader::loadObjModel("res/plant.myobject", loader);
	RawModel* tree = OBJLoader::loadObjModel("res/tree.myobject",loader);
	RawModel* fern = OBJLoader::loadObjModel("res/fern.myobject", loader);
	RawModel* smallTree = OBJLoader::loadObjModel("res/smallTree.myObject", loader);

	TerrainTexture backgroundTexture = TerrainTexture(loader.loadTexture("res/grass.jpg"));
	TerrainTexture rTexture = TerrainTexture(loader.loadTexture("res/sand.jpg"));
	TerrainTexture gTexture = TerrainTexture(loader.loadTexture("res/snow.jpg"));
	TerrainTexture bTexture = TerrainTexture(loader.loadTexture("res/water.jpg"));

	
	TerrainTexturePack texturePack = TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);
	

	TerrainTexture blendMap = TerrainTexture(loader.loadTexture("res/blendMap.png"));
	TerrainTexture blendMap2 = TerrainTexture(loader.loadTexture("res/blendMap2.png"));

	ModelTexture* treeTex = new ModelTexture(loader.loadTexture("res/tree.png"));			// Entities textures
	ModelTexture* dragTex = new ModelTexture(loader.loadTexture("res/dragon.png"));
	ModelTexture* stallTex = new ModelTexture(loader.loadTexture("res/stall.bmp"));
	ModelTexture* plantTex = new ModelTexture(loader.loadTexture("res/plant.png"));
	ModelTexture* fernTex = new ModelTexture(loader.loadTexture("res/plant.png"));
	ModelTexture* smallTreeTex = new ModelTexture(loader.loadTexture("res/smallTree.png"));

	ModelTexture* grassTex = new ModelTexture(loader.loadTexture("res/grass.jpg"));        // Terrain textures
	ModelTexture* waterTex = new ModelTexture(loader.loadTexture("res/water2.jpg"));

	dragTex->setShineDamper(10);
	dragTex->setReflectivity(1);
	plantTex->setTransparency(true);
	plantTex->setFakeLighting(true);
	fernTex->setTransparency(true);

	TexturedModel* dragonModel = new TexturedModel(dragon, *dragTex);				
	TexturedModel* stallModel = new TexturedModel(stall, *stallTex);
	TexturedModel* plantModel = new TexturedModel(plant, *plantTex);
	TexturedModel* treeModel = new TexturedModel(tree, *treeTex);
	TexturedModel* fernModel = new TexturedModel(fern, *fernTex);
	TexturedModel* smallTreeModel = new TexturedModel(smallTree, *smallTreeTex);
	
	
	
	std::vector<Entity> allModels;
	std::vector<Entity> staticModels;

	srand(time(NULL));

	
	
	
	
	for (int i = 0; i < 200; i++)
	{
		float x = rand() % 500 * pow(-1, i);
		float y = 0;
		float z = rand() % 500 * pow(-1, i);
		Entity temp = Entity(*smallTreeModel, glm::vec3(x, y, z), 0, 0, 0, 5);
		staticModels.push_back(temp);
	}

	for (int i = 0; i < 200; i++)
	{
		float x = rand() % 500 * pow(-1, i);
		float y = 0;
		float z = rand() % 500 * pow(-1, i);
		Entity temp = Entity(*fernModel, glm::vec3(x, y, z), 0, 0, 0, 1);
		staticModels.push_back(temp);
	}
	for (int i = 0; i < 200; i++)
	{
		float x = rand() % 500 * pow(-1, i);
		float y = 0;
		float z = rand() % 500 * pow(-1, i);
		Entity temp = Entity(*plantModel, glm::vec3(x, y, z), 0, 0, 0, 3);
		staticModels.push_back(temp);
	}
	for (int i = 0; i < 50; i++)
	{
		float x = rand() % 500 * pow(-1, i);
		float y = 0;
		float z = rand() % 500 * pow(-1, i);
		Entity temp = Entity(*treeModel, glm::vec3(x, y, z), 0, 0, 0, 1);
		staticModels.push_back(temp);
	}
	
	
	
	for (int i = 0; i < 10; i++)
	{

		


		float x = rand() % 10 *10 *pow(-1,i);
		float y = 2;
		float z = rand() % 10 * -30;
		Entity temp = Entity(*dragonModel, glm::vec3(x, y, z), 0, rand() % 10, 0, 1);
		Entity temp2 = Entity(*stallModel, glm::vec3(x, y, z), 0, rand() % 10, 0, 1);
		allModels.push_back(temp);
		allModels.push_back(temp2);


	}
	
	
	

	Light light = Light(glm::vec3(400, 900, 200),glm::vec3(1,1,1));
	
	Terrain terrain = Terrain(0,0,loader, texturePack, blendMap);
	
	Terrain terrain2 = Terrain(1, 0, loader, texturePack, blendMap2);
	Terrain terrain3 = Terrain(0, 1, loader, texturePack, blendMap);
	Terrain terrain4 = Terrain(1, 1, loader, texturePack, blendMap);
	Terrain terrain5 = Terrain(-1, 0, loader, texturePack, blendMap);
	Terrain terrain6 = Terrain(0, -1, loader, texturePack, blendMap);
	Terrain terrain7 = Terrain(-1, -1, loader, texturePack, blendMap);
	Terrain terrain8 = Terrain(-1, 1, loader, texturePack, blendMap);
	Terrain terrain9 = Terrain(1, -1, loader, texturePack, blendMap);


	Camera camera = Camera();
	
	
	

	double lastTime = glfwGetTime();
	int nbFrames = 0;
	MasterRenderer renderer = MasterRenderer();
	while (!display.checkIfWindowOpen())
	{

		
		double currentTime = glfwGetTime();
		nbFrames++;
		if (currentTime - lastTime >= 1.0) {
			printf("%f ms/frame   fps:  %f \n", 1000.0 / double(nbFrames), (float)nbFrames);             // Print spf and fps to console.
			printf("Camera x: %.2f, y: %.2f, z: %.2f,   Yaw: %.2f, Pitch: %.2f, Roll: %.2f\n\n", camera.getPosition().x, camera.getPosition().y, camera.getPosition().z, camera.getYaw(), camera.getPitch(), camera.getRoll());
			nbFrames = 0;
			lastTime += 1.0;
		}

		

		

		for (int i = 0; i < staticModels.size(); i++)
		{
			renderer.processEntity(staticModels[i]);
		}

		for (int i = 0; i < 20; i++)
			allModels[i].increaseRotation(0, 2, 0);																	// Rotate objects.
		camera.move(display);
		
		//game logic
	
		renderer.processTerrain(terrain);
		renderer.processTerrain(terrain2);
		renderer.processTerrain(terrain3);
		renderer.processTerrain(terrain4);
		renderer.processTerrain(terrain5);
		renderer.processTerrain(terrain6);
		renderer.processTerrain(terrain7);
		renderer.processTerrain(terrain8);
		renderer.processTerrain(terrain9);
		
		for (int i = 0; i < 20; i++)
			renderer.processEntity(allModels[i]);																	// Process each object.
		
		renderer.render(light,camera);
		display.updateDisplay();
		
	}
	saveCamera(camera);

	renderer.cleanUp();
	loader.cleanUP();
	display.closeDisplay();



	return 0;

}