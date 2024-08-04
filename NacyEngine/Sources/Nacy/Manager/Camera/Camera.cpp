#include "pch.h"
#include "Camera.h"

namespace Nacy {
    Camera::Camera(float left, float right, float bottom, float top) {
        this->projectionMatrix = glm::ortho(left, right, bottom, top);
    }

    void Camera::SetProjectionMatrix(const glm::mat4 &projection) {
        this->projectionMatrix = projection;
    }

    void Camera::SetPosition(const Vector2 &position) {
        this->position = position;
    }

    void Camera::SetRotation(float rotation) {
        this->rotation = rotation;
    }
}

