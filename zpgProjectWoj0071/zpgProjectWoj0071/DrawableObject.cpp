#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram)
    : model(model), shaderProgram(shaderProgram), transformation(glm::mat4(1.0f)) {
  
    }

void DrawableObject::setPosition(glm::vec3 position) {
	this->position = position;
}

void DrawableObject::setTransformation(const glm::mat4& transform) {
    transformation = transform;
}

void DrawableObject::addTransformation(std::shared_ptr<Transformation> transformation) {
    transformations.push_back(transformation);
}

void DrawableObject::applyTransformations() {
    int i = 0;
    glm::mat4 result = glm::mat4(1.0f);
    for (const auto& transform : transformations) {
		result = transform->apply(result);
    }
    setTransformation(result);
}


void DrawableObject::draw() const {
    model->bind();
   
    shaderProgram->useProgram();

    // Apply transformation
    shaderProgram->makeTransformationForMultipleObjects(transformation);

    // Draw the model
    glDrawArrays(model->getShapeType(), model->getFirst(), model->getCount());
}

