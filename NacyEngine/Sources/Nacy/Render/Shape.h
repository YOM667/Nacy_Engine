#pragma once
#include "Renderer.h"

#include "Nacy/Manager/Shader/Shader.h"
#include "Nacy/Math/Vector.h"
#include "Nacy/Core/Core.h"
namespace Nacy
{
    class ShapeRenderer
    {
    public:

        NACY_API ShapeRenderer();
        NACY_API ~ShapeRenderer();

        NACY_API void DrawRect(float x, float y, float width, float height, const RGBA& color, float scale);
        NACY_API void DrawRoundedRect(float x, float y, float width, float height, float radius ,const RGBA& color, float scale);
        NACY_API void DrawRoundedRectOutline(float x, float y, float width, float height, float radius, float outlineThickness, const RGBA& outlineColor, const RGBA& internalColor, float scale);

    private:
        Renderer* rectRenderer;
        Renderer* roundedRectRenderer;
        Renderer* roundedRectOutlinRenderer;

    };
}