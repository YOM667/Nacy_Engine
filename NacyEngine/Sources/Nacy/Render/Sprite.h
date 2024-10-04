#pragma once

#include "Renderer.h"
#include "Texture.h"

#include "Nacy/Core/Core.h"

#include "Nacy/Manager/Shader/Shader.h"
#include "Nacy/Math/Vector.h"

namespace Nacy {
    class SpriteRenderer {
    public:

        NACY_API SpriteRenderer();

        NACY_API ~SpriteRenderer();

        NACY_API void UpdateWindowSize(const Vector2& size) {
            this->windowSize = size;
        }

        NACY_API void DrawSprite(const Texture2D &texture, const Vector2 &position, const Vector2 &size,
                                 const RGBA &color = RGBA(255.0f, 255.0f, 255.0f, 255.0f));

        NACY_API void DrawRoundedSprite(const Texture2D &texture, const Vector2 &position, const Vector2 &size, float radius, float scale,
                          const RGBA &color = RGBA(255.0f, 255.0f, 255.0f, 255.0f));

    private:
        Vector2 windowSize;
        Renderer *spriteRenderer;
        Renderer *spriteRoundRenderer;
    };
}