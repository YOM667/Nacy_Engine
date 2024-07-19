#pragma once
#include "Shader.h"
#include "Texture.h"
#include "Nacy/Core/Core.h"
namespace Engine
{
    class SpriteRenderer
    {
    public:
       
        NACY_API SpriteRenderer(Shader&& shader);
        NACY_API ~SpriteRenderer();

        NACY_API void DrawSprite(Texture2D& texture,
            glm::vec2 position,
            glm::vec2 size,
            glm::vec4 color = glm::vec4(1.0f));


    private:
        Shader spriteShader;
        GLuint VAO;

        glm::vec2 windowSize;
        void init();
    };
}