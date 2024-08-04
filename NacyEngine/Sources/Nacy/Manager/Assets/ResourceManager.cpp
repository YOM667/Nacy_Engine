#include "pch.h"
#include "ResourceManager.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

namespace Nacy {
    std::map<std::string, Shader> ResourceManager::shaders = std::map<std::string, Shader>() = {};
    std::map<std::string, Texture2D> ResourceManager::textures = std::map<std::string, Texture2D>() = {};
    std::map<std::string, TextRenderer> ResourceManager::fonts = std::map<std::string, TextRenderer>() = {};

    Shader ResourceManager::LoadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *name) {
        Shader shader;
        shader.LoadFileAndCompile(vShaderFile, fShaderFile);
        shaders[name] = shader;
        return shader;
    }

    Texture2D ResourceManager::LoadTextureFromFile(const char *file, GLboolean alpha) {
        Texture2D texture;
        int width, height, channel;
        if (alpha) {
            texture.imageFormat = GL_RGBA;
            texture.internalFormat = GL_RGBA;
        }
        const auto data = stbi_load(file, &width, &height, &channel, 0);
        texture.Generate(width, height, data);

        return texture;
    }

    Shader ResourceManager::LoadShader(const char *vertexCode, const char *fragmentCode, const char *name) {
        Shader shader;
        shader.Compile(vertexCode, fragmentCode);
        shaders[name] = shader;
        return shader;
    }

    Shader ResourceManager::GetShader(const char *name) {
        return shaders[name];
    }

    Texture2D ResourceManager::LoadTexture2D(const char *file, const bool alpha, const char *name) {
        const auto texture = LoadTextureFromFile(file, alpha);
        textures[name] = texture;
        return texture;
    }

    Texture2D ResourceManager::GetTexture2D(const char *name) {
        return textures[name];
    }

    TextRenderer ResourceManager::GetFont(const char *name) {
        return fonts[name];
    }

    void ResourceManager::LoadFont(const char *file, float fontSize, const char *name) {
        TextRenderer font;
        font.Load(file, fontSize);
        fonts[name] = font;
    }

}
