#pragma once
#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "Models.h"
#include "ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <memory>

class DrawableObject {
public:
    DrawableObject(Model* model, ShaderProgram* shaderProgram);
	void setPosition(glm::vec3 position);
    void setTransformation(const glm::mat4& transform);
    void addTransformation(std::shared_ptr<Transformation> transformation);
    //void addTransformation(Transformation* transformation);
    void applyTransformations();

    void draw() const;

private:
    // Bind VAO and use shader program only if they are not already bound
    Model* model;
    ShaderProgram* shaderProgram;
    glm::mat4 transformation;
    glm::vec3 position;
    std::vector<std::shared_ptr<Transformation>> transformations;
};

#endif // DRAWABLEOBJECT_H

