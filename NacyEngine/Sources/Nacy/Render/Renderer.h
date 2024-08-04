#pragma once

#include "Nacy/Manager/Shader/Shader.h"
#include <Nacy/Math/Vector.h>

namespace Nacy {
    class Renderer {
    private:
        unsigned int VAO, VBO, EBO;
        Shader shader;


        void InitData();

    public:
        Vector2 position, size;
        float rotate, scale;

        NACY_API explicit Renderer(const Shader &&shader);

        NACY_API Shader &GetShader();

        NACY_API uint32_t GetVAO();

        NACY_API void SetVAO(unsigned int VAO);

        NACY_API void CustomDraw();

        NACY_API void Draw(const Vector2 &position, const Vector2 &size);

    };

}

