#pragma once

#include "Nacy/Core/Core.h"
#include <glm/glm.hpp>
namespace Engine
{
    class NACY_API Shader
    {
    public:
        uint32_t ID;
        Shader();
        void use() const;
        Shader& useShader();
        void loadFileAndCompile(const char* vertexPath, const char* fragmentPath);
        void compile(const char* vertexCode, const char* fragmentCode);
        void attachShader(unsigned int vertex, unsigned int fragment);
        unsigned int createShader(const char* shaderCode, const char* shaderType);

        void setInt(const char* name, int num) const;
        void setFloat(const char* name, float num) const;
        void setDouble(const char* name, double num) const;
        void setBool(const char* name, bool value) const;
        void setVector1F(const char* name, glm::vec1 vec) const;
        void setVector2F(const char* name, glm::vec2 vec) const;
        void setVector3F(const char* name, glm::vec3 vec) const;
        void setVector4F(const char* name, glm::vec4 vec) const;
        void setMatrix2F(const char* name, const glm::mat2& mat2) const;
        void setMatrix3F(const char* name, const glm::mat3& mat3) const;
        void setMatrix4F(const char* name, glm::mat4 mat4) const;
    private:
        static void checkCompileErrors(unsigned int shader, std::string type);
    };
}
