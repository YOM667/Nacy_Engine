#pragma once

#include "Nacy/Math/Vector.h"

namespace Nacy {
    class Camera {
    public:
        Camera(float left, float right, float bottom, float top);

        void SetProjectionMatrix(const glm::mat4 &projection);

        void SetPosition(const Vector2 &position);

        void SetRotation(float rotation);

        const Vector2 &GetPosition() const {
            return this->position;
        }

        const glm::mat4 &GetPorjectionMatrix() const {
            return this->projectionMatrix;
        }

        const float GetRotation() const {
            return this->rotation;
        }

    private:
        Vector2 position;

        float rotation;

        glm::mat4 projectionMatrix;
    };

}

