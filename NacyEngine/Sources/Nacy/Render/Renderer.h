#pragma once
#include "Nacy/Manager/Shader/Shader.h"
namespace Nacy
{
	class Renderer
	{
	private:
		unsigned int VAO, VBO, EBO;
		Shader shader;

		void InitData();
	public:
		float x, y, width, height, rotate, scale;
		NACY_API Renderer(const Shader&& shader, float x = 0, float y = 0, float width = 0, float height = 0);
		NACY_API inline Shader& GetShader();
		NACY_API inline unsigned int GetVAO();
		NACY_API inline void SetVAO(unsigned int VAO);
		NACY_API void CustomDraw();
		NACY_API void Draw();

	};

}

