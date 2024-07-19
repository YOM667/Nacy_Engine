#pragma once

#include "Nacy/Core/Core.h"

#include "Texture.h"
#include "Shader.h"

namespace Engine
{


    struct Character {
        GLuint TextureID;   // ID handle of the glyph texture
        glm::ivec2 Size;    // Size of glyph
        glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
        GLuint Advance;     // Horizontal offset to advance to next glyph
    };

    class TextRenderer
    {
    public:
        NACY_API TextRenderer();
        NACY_API ~TextRenderer();
        NACY_API void load(std::string font, uint32_t fontSize);
        NACY_API void renderText(std::string text, float x, float y, float scale, glm::vec4 color);
        NACY_API void renderCenterdText(std::string text, float x, float y, float scale, glm::vec4 color);
        NACY_API glm::vec2 getTextSize(std::string text, float scale);
        std::map<GLchar, Character> characters;
        Shader textShader;
    private:
        glm::mat4 transform;
        uint32_t VAO, VBO,EBO;
    };

    class FontRenderer
    {
    public:
        NACY_API void load(const char* file, float fontSize, const char* name);
        NACY_API TextRenderer getFont(const char* fontName);
    };
}
