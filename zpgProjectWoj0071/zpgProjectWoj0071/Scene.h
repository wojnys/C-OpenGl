#pragma once
#include <vector>
#include "DrawableObject.h"
#include <GLFW/glfw3.h>
#include "Controller.h"
#include "Camera.h"
class Scene {
public:
	Scene(GLFWwindow* window, ShaderProgram* shaderProgram, Camera* camera);
    void addDrawableObject(DrawableObject* drawableObjects);
    void render();
    void clear();
	Controller* getController();

private:
    std::vector<DrawableObject*> drawableObjects;

    float deltaTime;
	float lastFrame;
	int frameCount = 0;
	float lastTime = 0.0f;
	GLFWwindow* window;
	ShaderProgram* shaderProgram;
	Controller* controller;
	Camera* camera;

};

