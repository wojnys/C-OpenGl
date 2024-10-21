#include "Application.h"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Application::Application() {
	std::cout << "APP was started";
}
Application::~Application() {
	std::cout << "APP was destroyed";
	
}

void Application::error_callback(int error, const char* description) { fputs(description, stderr); }

float Application::generateRandomFloatNumber(float bottomBoundary, float upBoundary) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(bottomBoundary, upBoundary);

	return dis(gen);
}

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	//printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Application::window_focus_callback(GLFWwindow* window, int focused) { 
	//printf("window_focus_callback \n");
	}

void Application::window_iconify_callback(GLFWwindow* window, int iconified) {
	//printf("window_iconify_callback \n"); 
	}

void Application::window_size_callback(GLFWwindow* window, int width, int height) {
	//printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Application::cursor_callback(GLFWwindow* window, double x, double y) { 
	//printf("cursor_callback \n"); 
	}

void Application::button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}


void Application::initialization() {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	this->window = glfwCreateWindow(1000, 1000, "ZPG", NULL, NULL);

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glEnable(GL_DEPTH_TEST); //Z-buffer
	glEnable(GL_CULL_FACE); // odstranuje zadne steny


	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetMouseButtonCallback(window, button_callback);
	glfwSetWindowFocusCallback(window, window_focus_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);

	glewExperimental = GL_TRUE;
	glewInit();

	//this->info();

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);

}

void Application::createShaders() {
	//const char* vertex_shader =
	//	"#version 330 core\n"
	//	"layout(location=0) in vec3 vp;"
	//	"layout(location=1) in vec3 color;"
	//	"out vec3 fragColor;"
	//	"uniform mat4 transform;"
	//	"void main () {"
	//	"     gl_Position = transform * vec4(vp, 1.0);"
	//	"     fragColor = color;"
	//	"}";


	//const char* fragment_shader =
	//	"#version 330\n"
	//	"in vec3 fragColor;"
	//	"out vec4 frag_colour;"
	//	"void main () {"
	//	"     frag_colour = vec4(fragColor, 1.0);"
	//	"}";

	const char* vertex_shader =
		"#version 330\n"
		"uniform mat4 modelMatrix;"
		"uniform mat4 projectMatrix;"
		"uniform mat4 viewMatrix;"
		"out vec3 vertexColor;"
		"layout(location=0) in vec3 vp;"
		"layout(location=1) in vec3 vn;"
		"void main () {"
		"     vertexColor=vn;"
		"     gl_Position = projectMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);"
		"}";


	const char* fragment_shader =
		"#version 330\n"
		"out vec4 frag_colour;"
		"in vec3 vertexColor;"
		"void main () {"
		"     frag_colour = vec4(vertexColor, 0.0);"
		"}";

	const char* fragment_shader_red =
		"#version 330\n"
		"out vec4 frag_colour;"
		"in vec3 vertexColor;"
		"void main () {"
		"     frag_colour = vec4(1.0, 0.0, 0.0, 1.0);"
		"}";


	AppVertexShader* vertexShader = new AppVertexShader(vertex_shader);
	AppFragmentShader* fragmentShader = new AppFragmentShader(fragment_shader);


	this->shaderProgram.push_back(new ShaderProgram(vertexShader, fragmentShader));


	AppFragmentShader* fragmentShader1 = new AppFragmentShader(fragment_shader_red);
	this->shaderProgram.push_back(new ShaderProgram(vertexShader, fragmentShader1));
}


void Application::createModels() {

	Model* treeModel = new Model(tree, sizeof(tree), GL_TRIANGLES, 0, sizeof(tree) / 6);
	for (int i = 0; i < 50; i++) {
		float randX = generateRandomFloatNumber(-100.0f, 100.0f);
		float randY = generateRandomFloatNumber(-100.0f, 40.0f);
		float randZ = generateRandomFloatNumber(-40.0f, 40.0f);
	
		DrawableObject* tree = new DrawableObject(treeModel, this->shaderProgram[0]);

		tree->addTransformation(std::make_shared<Translate>(randX, 1.0f, randZ));
		tree->addTransformation(std::make_shared<Scale>(0.9f, 0.9f, 1.0f));
		tree->addTransformation(std::make_shared<Rotate>(10.0f,0.0f, 0.0f, 0.75f));
		tree->applyTransformations();
		drawableObjects.push_back(tree);
	}


	Model* bushModal = new Model(bushes, sizeof(bushes), GL_TRIANGLES, 0, sizeof(bushes) / 6);
	for (int i = 0; i < 50; i++) {
		float randX = generateRandomFloatNumber(-40.0f, 40.0f);
		float randY = generateRandomFloatNumber(-40.0f, 40.0f);
		float randZ = generateRandomFloatNumber(-40.0f, 40.0f);

		DrawableObject* bush = new DrawableObject(bushModal, this->shaderProgram[0]);
		bush->addTransformation(std::make_shared<Translate>(randX, 1.0f, randZ));
		bush->addTransformation(std::make_shared<Scale>(0.7f, 0.7f, 0.7f));
		bush->applyTransformations();
		drawableObjects.push_back(bush);
	}
}

void Application::run() {
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 20.0f);
	glm::vec3  cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 10.0f, 0.0f);

	Camera* camera = new Camera(cameraPos, cameraFront, cameraUp,-90.0f, 0.0f, 45.0f);

	// I need to fix -> how on one scene can call multiple shaderPrograms -> 
	Scene* scene1 = new Scene(window, this->shaderProgram[0], camera);
	Scene* scene2 = new Scene(window, this->shaderProgram[0], camera);


	// Set the user pointer to the controller of the first scene
	glfwSetWindowUserPointer(window, scene1->getController()); // Assuming you have a getController() method in Scene

	// Set the mouse callback for the window
	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
		Controller* controller = static_cast<Controller*>(glfwGetWindowUserPointer(window));
		if (controller) {
			controller->mouseCallback(window, xpos, ypos); // Call the mouse callback
		}
	});

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	scenes.push_back(scene1);
	scenes.push_back(scene2);

	int currentSceneIndex = 0;
	// add drawableObject into the scene

	for (DrawableObject* obj : this->drawableObjects) {
		scenes[0]->addDrawableObject(obj);
	}
	
	glEnable(GL_DEPTH_TEST); //Z-buffer
	glEnable(GL_CULL_FACE);
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// thi replaced the generating for models and shaders
		scenes[currentSceneIndex]->render();

		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
		// update other events like input handling
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}