#include "pch.h"
#include "Shader.h"

namespace Nacy
{
    Shader::Shader() : ID(0)
    {

    }
    void Shader::LoadFileAndCompile(const char* vertexPath, const char* fragmentPath)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure stream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        Compile(vShaderCode, fShaderCode);
    }
    void Shader::Compile(const char* vertexCode, const char* fragmentCode)
    {
        GLuint vertex, fragment;

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertexCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragmentCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // Shader Program
        this->ID = glCreateProgram();
        glAttachShader(this->ID, vertex);
        glAttachShader(this->ID, fragment);
        glLinkProgram(this->ID);
        checkCompileErrors(this->ID, "PROGRAM");
        // Delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }
    unsigned int Shader::CreateShader(const char* shaderCode, const char* shaderType)
    {
        unsigned int shader = 0;
        if (shaderType == "VERTEX") 
            shader = glCreateShader(GL_VERTEX_SHADER);
        else
            shader = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(shader, 1, &shaderCode, nullptr);
        glCompileShader(shader);
        if (shaderType != 0)
        {
            checkCompileErrors(shader, shaderType);
        }
        return shader;
    }
    void Shader::AttachShader(unsigned int vertex,unsigned int fragment)
    {
        this->ID = glCreateProgram();
        glAttachShader(this->ID, vertex);
        glAttachShader(this->ID, fragment);
        glLinkProgram(this->ID);
        checkCompileErrors(this->ID, "PROGRAM");
    }
    // activate the shader
    // ------------------------------------------------------------------------
    void Shader::Use() const
    {
        glUseProgram(this->ID);
    }
    Shader& Shader::UseShader()
    {
        glUseProgram(this->ID);
        return *this;
    }
    // utility uniform functions
    // ------------------------------------------------------------------------
    void Shader::SetBool(const char* name, bool value) const
    {
        glUniform1i(glGetUniformLocation(this->ID, name), (int)value);
    }
    void Shader::checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
    void Shader::SetVector1F(const char* name, const glm::vec1& vec) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform1f(loc, vec.x);
    }
    void Shader::SetVector2F(const char* name, const glm::vec2& vec) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform2f(loc, vec.x, vec.y);
    }
    void Shader::SetVector3F(const char* name, const glm::vec3& vec) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform3f(loc, vec.x, vec.y, vec.z);
    }
    void Shader::SetVector4F(const char* name, const glm::vec4& vec) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform4f(loc, vec.x, vec.y, vec.z, vec.w);
    }
    void Shader::SetMatrix2F(const char* name, const glm::mat2& mat) const {
        int loc = glGetUniformLocation(this->ID, name);
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
    }
    void Shader::SetMatrix3F(const char* name, const glm::mat3& mat) const {
        int loc = glGetUniformLocation(this->ID, name);
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
    }
    void Shader::SetMatrix4F(const char* name, const glm::mat4& mat) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
    }
    void Shader::SetInt(const char* name, int num) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform1i(loc, num);
    }
    void Shader::SetFloat(const char* name, float num) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform1f(loc, num);
    }
    void Shader::SetDouble(const char* name, double num) const
    {
        int loc = glGetUniformLocation(this->ID, name);
        glUniform1d(loc, num);
    }
}

