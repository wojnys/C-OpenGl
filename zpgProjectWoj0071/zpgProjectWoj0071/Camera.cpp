#include "Camera.h"

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraFron, glm::vec3 cameraUp, float yaw, float pitch, float fov) {
	this->cameraPosition = cameraPosition;
	this->cameraFront = cameraFront;
	this->cameraUp = cameraUp;
	this->yaw = yaw;
	this->pitch = pitch;
	this->fov = fov;
}

void Camera::moveFowrard(float cameraSpeed) {
	this->cameraPosition += cameraSpeed * this->cameraFront;
}
void Camera::moveBackward(float cameraSpeed) {
	this->cameraPosition -= cameraSpeed * this->cameraFront;
}
void Camera::moveLeft(float cameraSpeed) {
	this->cameraPosition -= glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * cameraSpeed;
}
void Camera::moveRight(float cameraSpeed) {
	this->cameraPosition += glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * cameraSpeed;
}
void Camera::moveMousePosition(glm::vec3 front) {
	this->cameraFront = glm::normalize(front);
}

glm::mat4 Camera::getCamera(void) {
	return this->viewMatrix;
}

glm::mat4 Camera::getProjection(void) {
	return this->projectionMatrix;
}

void Camera::updateViewMatrix() {
	std::cout << "view matrix was updated" << std::endl;
	this->viewMatrix = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	this->notify(this->viewMatrix, this->projectionMatrix);
}

void Camera::updateProjectionMatrix() {
	std::cout << "projection matrix was updated" << std::endl;
	this->projectionMatrix = glm::perspective(glm::radians(this->fov), 4.0f / 3.0f, 0.1f, 100.0f);
	this->notify(this->viewMatrix, this->projectionMatrix);
}













