
#pragma once  // Ensures the header is only included once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "vector"
#include "Observer.h"
#include "Subject.h"

class Camera :  public Subject {
public:
	Camera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp, float yaw, float pitch, float fov);

	void updateViewMatrix();
	void updateProjectionMatrix();
	glm::mat4 getCamera(void); // get  viewMatrix
	glm::mat4 getProjection(void); // getProjectionMatrix
	void moveFowrard(float cameraSpeed);
	void moveBackward(float camerSpeed);
	void moveLeft(float cameraSpeed);
	void moveRight(float cameraSpeed);

	void moveMousePosition(glm::vec3 front);

	float yaw;
	float pitch;
	float fov;

private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 cameraPosition;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	bool viewMatrixUpdated;
	bool projectionMatrixUpdated;

	std::vector<Observer*> observers;
};