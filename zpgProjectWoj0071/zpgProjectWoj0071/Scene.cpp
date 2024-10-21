#include "Scene.h"


Scene::Scene(GLFWwindow* window, ShaderProgram* shaderProgram, Camera* camera) {
	this->window = window;
	this->deltaTime = 0.0f;
	this->lastFrame = 0.0f;
   this->shaderProgram = shaderProgram;
	this->controller = new Controller(window, camera);
	this->camera = camera;
	this->frameCount = 0;

    // I need to setup for more shaderPrograms
    camera->attach(this->shaderProgram);
}

void Scene::addDrawableObject(DrawableObject* drawableObject) {
    this->drawableObjects.push_back(drawableObject);
}

Controller* Scene::getController() {
	return this->controller;
}

void Scene::render() {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    frameCount++;

    if (currentFrame - lastTime >= 1.0f) {
        float fps = frameCount / (currentFrame - lastTime);
        std::cout << "FPS: " << fps << std::endl;
        frameCount = 0;
        lastTime = currentFrame;
    }

	this->controller->processInput(deltaTime);

	for (DrawableObject* drawable : this->drawableObjects) {
		drawable->draw();
	}
}

void Scene::clear() {
    drawableObjects.clear();
}