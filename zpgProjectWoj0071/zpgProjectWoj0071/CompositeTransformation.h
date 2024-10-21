#pragma once
#ifndef COMPOSITETRANSFORMATION_H
#define COMPOSITETRANSFORMATION_H

#include "Transformation.h"
#include <vector>
#include <memory>

class CompositeTransformation : public Transformation {
public:
    void addTransformation(std::shared_ptr<Transformation> transformation) {
        transformations.push_back(transformation);
    }

    glm::mat4 apply(const glm::mat4& model) const override {
        glm::mat4 result = model;
        for (const auto& transformation : transformations) {
            result = transformation->apply(result);
        }
        return result;
    }

private:
    std::vector<std::shared_ptr<Transformation>> transformations;
};

#endif // COMPOSITETRANSFORMATION_H
