#include "pch.h"

#include "Text.h"
#include "Nacy/Manager/Assets/ResourceManager.h"
#include "Nacy/Manager/OpenGL/GLManager.h"

namespace Nacy {
    TextRenderer::TextRenderer() :
            transform(glm::mat4(0)) {
        this->renderer = new Renderer(ResourceManager::GetShader("textShader"));
        this->renderer->GetShader().Use();
        this->renderer->GetShader().SetInt("text", 0);
    }

    TextRenderer::~TextRenderer() {
        //if (this->renderer != nullptr)
        //{
        //	delete this->renderer;
        //}
    }

    void TextRenderer::Load(std::string font, float fontSize) {
        characters.clear();

        FT_Library ft;
        if (FT_Init_FreeType(&ft)) {
            std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        }

        FT_Face face;
        if (FT_New_Face(ft, font.c_str(), 0, &face)) {
            std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
        }

        FT_Set_Pixel_Sizes(face, 0, static_cast<uint32_t>(fontSize));

        if (FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
        }

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

        for (unsigned char c = 0; c < 128; c++) {
            // load character GLCall(glyph
            if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                continue;
            }

            // generate texture
            unsigned int texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RED,
                    face->glyph->bitmap.width,
                    face->glyph->bitmap.rows,
                    0,
                    GL_RED,
                    GL_UNSIGNED_BYTE,
                    face->glyph->bitmap.buffer
            );

            // set texture options
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            // now store character for later use
            Character character = {
                    texture,
                    glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                    glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                    static_cast<GLuint>(face->glyph->advance.x)
            };

            characters.insert(std::pair<char, Character>(c, character));
        }

        FT_Done_Face(face);
        FT_Done_FreeType(ft);
    }

    void TextRenderer::RenderText(std::string text, const Vector2 &position, float scale, const RGBA &color) {


        GL::GLManager::CullFace();
        GL::GLManager::Blend();
        GL::GLManager::BlendFunc(NACY_GL_SRC_ALPHA, NACY_GL_ONE_MINUS_SRC_ALPHA);
        int newX = position.x;
        // activate corresponding render state
        this->renderer->GetShader().Use();
        this->renderer->GetShader().SetVector4F("textColor", glm::vec4(color.red / 255.0f,
                                                                     color.green /
                                                                     255.0f,
                                                                     color.blue /
                                                                     255.0f,
                                                                     color.alpha /
                                                                     255.0f));

        // iterate through all characters
        std::string::const_iterator c;
        for (c = text.begin(); c != text.end(); c++) {
            glActiveTexture(GL_TEXTURE0);
            Character ch = characters[*c];

            float xPos = newX + ch.Bearing.x * scale;
            float yPos = position.y + (this->characters['H'].Bearing.y - ch.Bearing.y) * scale;

            float w = ch.Size.x * scale;
            float h = ch.Size.y * scale;
            glm::mat4 transform(1.0f);
            // update VBO for each character
            transform = glm::translate(transform, glm::vec3(glm::vec2(xPos, yPos), 0.0f));
            transform = glm::scale(transform, glm::vec3(w, h, 1.0f));

            this->renderer->GetShader().SetMatrix4F("transform", transform);

            glBindTexture(GL_TEXTURE_2D, ch.TextureID);

            glBindVertexArray(this->renderer->GetVAO());
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            newX += (ch.Advance >> 6) * scale;
        }
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        GL::GLManager::DisableBlend();
        GL::GLManager::DisableCullFace();
    }

    void TextRenderer::RenderCenterdText(std::string text, const Vector2& position, float scale, const RGBA &color) {
        this->RenderText(text, Vector2(position.x - (this->GetTextSize(text, scale).x / 2.0f), position.y), scale, color);
    }

    glm::vec2 TextRenderer::GetTextSize(std::string text, float scale) {
        std::string::const_iterator c;
        int x = 0;
        Character lastCharacter{};
        float caseY = 0;
        if (!std::all_of(text.begin(), text.end(), islower)) {
            caseY = characters['H'].Size.y;
        }
        for (c = text.begin(); c != text.end(); c++) {
            Character ch = characters[*c];
            x += (ch.Advance / 64) * scale;
        }
        float y = caseY;
        return glm::vec2(x, y);

    }

    void FontRenderer::Load(const char *file, float fontSize, const char *name) {
        ResourceManager::LoadFont(file, fontSize, name);
    }

    TextRenderer FontRenderer::GetFont(const std::string& fontName)
    {
        return ResourceManager::GetFont(fontName.c_str());
    }
}