#pragma once
#include "Renderer.h"
#include "Texture.h"

#include "Nacy/Core/Core.h"

#include "Nacy/Manager/Shader/Shader.h"
#include "Nacy/Math/Vector.h"
namespace Nacy
{
    class SpriteRenderer
    {
    public:
       
        NACY_API SpriteRenderer();
        NACY_API ~SpriteRenderer();

        NACY_API void DrawSprite(Texture2D& texture,float x, float y, float width, float height, const RGBA& color = RGBA(255.0f, 255.0f, 255.0f, 255.0f));
        NACY_API void DrawRoundedSprite(Texture2D& texture, float x, float y, float width, float height,float radius,float scale, const RGBA& color = RGBA(255.0f, 255.0f, 255.0f, 255.0f));

    private:
        Renderer* spriteRenderer;
        Renderer* spriteRoundRenderer;
    };
}