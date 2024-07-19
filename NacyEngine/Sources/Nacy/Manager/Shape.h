#pragma once
#include "Shader.h"
#include "Nacy/Core/Core.h"
namespace Engine
{
    struct Shape
    {
        GLuint VAO, VBO;
    };
    class ShapeRenderer
    {
    public:

        NACY_API ShapeRenderer();
        NACY_API ~ShapeRenderer();

        NACY_API void drawRect(glm::vec2 position, glm::vec2 size, glm::vec4 color, float scale);

    private:
        Shader rectShader;
        GLuint VBO, VAO, EBO;

    };
}