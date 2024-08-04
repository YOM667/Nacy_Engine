#pragma once

#include "Nacy/Core/Core.h"
#include "Nacy/Math/Vector.h"
#include "Renderer.h"

namespace Nacy {
    struct Character {
        GLuint TextureID;   // ID handle of the glyph texture
        glm::ivec2 Size;    // Size of glyph
        glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
        GLuint Advance;     // Horizontal offset to advance to next glyph
    };

    class TextRenderer {
    public:
        NACY_API TextRenderer();

        NACY_API ~TextRenderer();

        NACY_API void Load(std::string font, float fontSize);

        NACY_API void RenderText(std::string text, const Vector2 &position, float scale, const RGBA &color);

        NACY_API void UpdateWindowSize(const Vector2& size) {
            this->windowSize = size;
        }

        NACY_API void RenderCenterdText(std::string text, const Vector2 &position, float scale, const RGBA &color);


        NACY_API glm::vec2 GetTextSize(std::string text, float scale);

    private:
        Vector2 windowSize;
        std::map<GLchar, Character> characters;
        Renderer *renderer;
        glm::mat4 transform;
    };

    class FontRenderer {
    public:
        NACY_API void Load(const char *file, float fontSize, const char *name);

        NACY_API TextRenderer GetFont(const char *fontName);
    };
}
