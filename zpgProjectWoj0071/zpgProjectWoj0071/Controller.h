#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Camera.h"

class Controller {
public:
    Controller(GLFWwindow* window, Camera* camera)
        : window(window), camera(camera), firstMouse(true), lastX(400), lastY(300) {}

    Camera* camera;

    void processInput(float deltaTime) {
        float cameraSpeed = 5.5f * deltaTime;

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            camera->moveFowrard(cameraSpeed);

            camera->updateViewMatrix();
            camera->updateProjectionMatrix();
	/*		camera->notifyObservers();*/
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            camera->moveBackward(cameraSpeed);
            camera->updateViewMatrix();
            camera->updateProjectionMatrix();
         /*   camera->notifyObservers();*/
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            camera->moveLeft(cameraSpeed);
            camera->updateViewMatrix();
            camera->updateProjectionMatrix();
         /*   camera->notifyObservers();*/
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            camera->moveRight(cameraSpeed);
            camera->updateViewMatrix();
            camera->updateProjectionMatrix();
         /*   camera->notifyObservers();*/
        }
    }

    void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
        if (firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }
        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

        float sensitivity = 0.1f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        camera->yaw += xoffset;
        camera->pitch += yoffset;

        if (camera->pitch > 89.0f)
            camera->pitch = 89.0f;
        if (camera->pitch < -89.0f)
            camera->pitch = -89.0f;

        glm::vec3 front;
        front.x = cos(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
        front.y = sin(glm::radians(camera->pitch));
        front.z = sin(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
        camera->moveMousePosition(front);

        camera->updateViewMatrix();
		camera->updateProjectionMatrix();
   /*     camera->notifyObservers();*/
    }

private:
    GLFWwindow* window;
    bool firstMouse;
    float lastX, lastY;
};

