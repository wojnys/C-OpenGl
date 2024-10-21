#pragma once 

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera;

class Observer {
public:
    virtual ~Observer() = default;

    // This method will be called whenever the Camera is updated
    virtual void onCameraUpdate(glm::mat4 updatedViewMatrix,glm::mat4 updatedProjectionMatrix) = 0;
};
