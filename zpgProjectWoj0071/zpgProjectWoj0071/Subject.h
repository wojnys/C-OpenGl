#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject {
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const glm::mat4 updatedViewMatrix, const glm::mat4 updatedProjectionMatrix);

private:
    std::vector<Observer*> observers;
};

#endif // SUBJECT_H

