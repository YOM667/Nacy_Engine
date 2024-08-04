#pragma once

#include "Nacy/Object/Components/Component.hpp"
#include "Nacy/Math/Vector.h"

namespace Nacy {
    struct TextLabelComponent : public Component {
        bool centered;
        RGBA color;
        const char *text;
        const char *font;

        explicit TextLabelComponent(const char *text, const char *font,
                                    RGBA color = RGBA(255.0f, 255.0f, 255.0f, 255.0f), bool centered = false)
                : text(text), font(font), color(color), centered(centered) {}

        static std::string GetStaticType() {
            return "lable";
        }

        std::string GetType() override {
            return "lable";
        }
    };
}


