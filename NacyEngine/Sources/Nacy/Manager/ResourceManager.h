#pragma once
#include "Shader.h"
#include "Texture.h"
#include "Text.h"
#include "Nacy/Core/Core.h"

namespace Engine
{
	class ResourceManager
	{
	private:

		NACY_API static Texture2D LoadTextureFromFile(const char* file, GLboolean alpha);
	public:
		static std::map<std::string, Shader> shaders;
		static std::map<std::string, Texture2D> textures;
		static std::map<std::string, TextRenderer> fonts;

		NACY_API static Shader LoadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* name);
		NACY_API static Shader LoadShader(const char* vertexCode, const char* fragmentCode, const char* name);
		NACY_API static Shader GetShader(const char* name);

		NACY_API static Texture2D LoadTexture2D(const char* file, bool alpha, const char* name);
		NACY_API static Texture2D GetTexture2D(const char* name);

		NACY_API static TextRenderer GetFont(const char* name);
		NACY_API static void LoadFont(const char* file, float fontSize, const char* name);
	};

}
