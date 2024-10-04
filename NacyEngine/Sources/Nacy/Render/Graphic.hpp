#pragma once

#include <memory>

#include "Nacy/Render/Sprite.h"
#include "Nacy/Render/Text.h"
#include "Nacy/Render/Shape.h"
#include "Nacy/Core/Core.h"

namespace Nacy {
    static std::unique_ptr<SpriteRenderer> SPRITE = nullptr;
    static std::unique_ptr<ShapeRenderer> SHAPE = nullptr;
    static std::unique_ptr<FontRenderer> TEXT = nullptr;
    class Graphic {
    private:

    public:

        static void Init() {
            SPRITE = std::make_unique<SpriteRenderer>();
            SHAPE = std::make_unique<ShapeRenderer>();
            TEXT = std::make_unique<FontRenderer>();
        }

        NACY_API static void UpdateWindowSize(const Vector2& size) {
            SPRITE->UpdateWindowSize(size);
            SHAPE->UpdateWindowSize(size);
        }

        NACY_API static void DrawSprite(const Texture2D& texture, const Vector2& position, const Vector2& size,
            const RGBA& color = RGBA(255.0f, 255.0f, 255.0f, 255.0f)) {
            SPRITE->DrawSprite(texture, position, size, color);
        }

        NACY_API static void DrawRoundedSprite(const Texture2D& texture, const Vector2& position, const Vector2& size, float radius, float scale,
            const RGBA& color = RGBA(255.0f, 255.0f, 255.0f, 255.0f)) {
            SPRITE->DrawRoundedSprite(texture, position, size,radius,1.0f, color);
        }
        NACY_API static void DrawRect(const Vector2& position, const Vector2& size, const RGBA& color, float scale) {
            SHAPE->DrawRect(position, size, color, scale);
        }

        NACY_API static void DrawRoundedRect(const Vector2& position, const Vector2& size, float radius, const RGBA& color, float scale) {
            SHAPE->DrawRoundedRect(position, size, radius ,color, scale);
        }

        NACY_API static void DrawRoundedRectOutline(const Vector2& position, const Vector2& size, float radius, float outlineThickness,
            const RGBA& outlineColor, const RGBA& internalColor, float scale) {
            SHAPE->DrawRoundedRectOutline(position, size, radius, outlineThickness, outlineColor, internalColor, scale);
        }

        NACY_API static void DrawText(const std::string& name, const std::string& text , const Vector2& position, const RGBA color ,float scale) {
            TEXT->GetFont(name).RenderText(text,position,scale,color);
        }

        NACY_API static void DrawCenteredText(const std::string& name, const std::string& text, const Vector2& position, const RGBA color, float scale) {
            TEXT->GetFont(name).RenderCenterdText(text, position, scale, color);
        }
    };
}

