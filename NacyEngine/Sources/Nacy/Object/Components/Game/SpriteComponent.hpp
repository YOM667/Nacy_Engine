#pragma once

#include "Nacy/Math/Vector.h"
#include "Nacy/Object/Components/Component.hpp"
#include "Nacy/Core/Core.h"
#include "Nacy/Render/Texture.h"

namespace Nacy {
    enum class SpriteType {
        NORMAL, ROUND
    };

    struct SpriteComponent : public Component {
        int zIndex;
        float radius;
        RGBA color;
        Texture2D texture;
        SpriteType spriteType;

        explicit SpriteComponent(
                Texture2D &texture,
                RGBA color = RGBA(255.0f, 255.0f, 255.0f, 255.0f),
                SpriteType spriteType = SpriteType::NORMAL,
                float radius = 0,
                int zIndex = 0) : radius(radius), texture(texture), zIndex(zIndex), color(color),
                                  spriteType(spriteType) {}

        static std::string GetStaticType() {
            return "sprite";
        }

        std::string GetType() override {
            return "sprite";
        }
    };


}

