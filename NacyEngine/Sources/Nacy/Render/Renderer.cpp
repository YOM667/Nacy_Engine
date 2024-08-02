#include "pch.h"
#include "Renderer.h"

namespace Nacy
{
	Renderer::Renderer(const Shader&& shader,float x, float y, float width, float height)
		: shader(shader), VAO(0), VBO(0), EBO(0), rotate(0), scale(1.0f), x(x), y(y), width(width), height(height)
	{
		this->InitData();
	}

	Shader& Renderer::GetShader()
	{
		return this->shader;
	}

	unsigned int Renderer::GetVAO()
	{
		return this->VAO;
	}

	inline void Renderer::SetVAO(unsigned int VAO)
	{
		this->VAO = VAO;
	}

	void Renderer::InitData()
	{
		float vertices[] = {
			1.0f, 1.0f, 0.0f,  // top right
			1.0f, 0.0f, 0.0f,  // bottom right
			0.0f, 0.0f, 0.0f,  // bottom left
			0.0f, 1.0f, 0.0f   // top left 
		};
		unsigned int indices[] = {
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Renderer::CustomDraw()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDisable(GL_BLEND);
		glBindVertexArray(0);
	}
	void Renderer::Draw()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glm::mat4 transform(1.0f);
		transform = glm::translate(transform, glm::vec3(x, y, 0.0f));

		transform = glm::translate(transform, glm::vec3(0.5f * (width), 0.5f * (height), 0.0f));
		transform = glm::scale(transform, glm::vec3(scale, scale, 1.0f));
		transform = glm::translate(transform, glm::vec3(-0.5f * (width), -0.5f * (height), 0.0f));

		transform = glm::scale(transform, glm::vec3(width, height, 1.0f));

		this->shader.Use();
		this->shader.SetMatrix4F("transform", transform);

		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glDisable(GL_BLEND);
	}

}

