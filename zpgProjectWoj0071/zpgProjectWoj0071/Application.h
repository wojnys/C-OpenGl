#ifndef APPLICATION_H
#define APPLICATION_H

#include <random>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Models.h"
#include "ShaderProgram.h"
#include "AppFragmentShader.h"
#include "AppVertexShader.h"
#include <vector>
#include "sphere.h"
#include "tree.h"
#include "bushes.h"
#include "gift.h"
#include "Scene.h"
#include "DrawableObject.h"
#include "Controller.h"

//#include "Camera.h"

class Application {
private:
    GLFWwindow* window;
    GLuint VBO, VAO;
    //std::vector<Model*> models;
    std::vector<ShaderProgram*> shaderProgram;
	std::vector<DrawableObject*> drawableObjects;

public:
    Application();
    ~Application();
    void initialization();
    void createShaders();
    void createModels();
    void run();
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void window_focus_callback(GLFWwindow* window, int focused);
    static void window_size_callback(GLFWwindow* window, int width, int height);
    static void window_iconify_callback(GLFWwindow* window, int iconified);
    static void cursor_callback(GLFWwindow* window, double x, double y);
    static void button_callback(GLFWwindow* window, int button, int action, int mode);
    static float generateRandomFloatNumber(float bottomBoundary, float upBoundary);

    std::vector<Scene*> scenes;
	Controller* controller;
};

#endif

