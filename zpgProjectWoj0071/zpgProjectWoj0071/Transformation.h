#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <vector>

class Transformation {
public:
    virtual glm::mat4 apply(const glm::mat4& model) const = 0;
};

class DefaultPosition : public Transformation {
    glm::vec3 defaultPosition;
public:
    DefaultPosition(float x, float y, float z) : defaultPosition(x, y, z) {}

    glm::mat4 apply(const glm::mat4& model) const override {
        return glm::translate(glm::mat4(1.0f), defaultPosition);
    }
};

class Scale : public Transformation {
    glm::vec3 scaleFactors;
public:
    Scale(float x, float y, float z) : scaleFactors(x, y, z) {}
    glm::mat4 apply(const glm::mat4& model) const override {
        return glm::scale(model, scaleFactors);
    }
};

class Rotate : public Transformation {
    float angle;
    glm::vec3 axis;
public:
    Rotate(float angle, float x, float y, float z) : angle(angle), axis(x, y, z) {}
    glm::mat4 apply(const glm::mat4& model) const override {
        return glm::rotate(model, glm::radians(angle), axis);
    }
};

class Translate : public Transformation {
    glm::vec3 translation;
public:
    Translate(float x, float y, float z) : translation(x, y, z) {}
    glm::mat4 apply(const glm::mat4& model) const override {
        return glm::translate(model, translation);
    }
};


