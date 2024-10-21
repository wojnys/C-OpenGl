#include "Subject.h"

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const glm::mat4 updatedViewMatrix, const glm::mat4 updatedProjectionMatrix) {
    for (Observer* observer : observers) {
        observer->onCameraUpdate(updatedViewMatrix, updatedProjectionMatrix);
    }
}
