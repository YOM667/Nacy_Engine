#pragma once

#include "Renderer.h"

#include "Nacy/Manager/Shader/Shader.h"
#include "Nacy/Math/Vector.h"
#include "Nacy/Core/Core.h"

namespace Nacy {
    class ShapeRenderer {
    public:

        NACY_API ShapeRenderer();

        NACY_API ~ShapeRenderer();

        NACY_API void UpdateWindowSize(const Vector2& size) {
            this->windowSize = size;
        }

        NACY_API void DrawRect(const Vector2 &position, const Vector2 &size, const RGBA &color, float scale);

        NACY_API void DrawRoundedRect(const Vector2 &position, const Vector2 &size, float radius, const RGBA &color, float scale);

        NACY_API void DrawRoundedRectOutline(const Vector2 &position, const Vector2 &size, float radius, float outlineThickness,
                               const RGBA &outlineColor, const RGBA &internalColor, float scale);

    private:
        Vector2 windowSize;
        Renderer *rectRenderer;
        Renderer *roundedRectRenderer;
        Renderer *roundedRectOutlinRenderer;

    };
}