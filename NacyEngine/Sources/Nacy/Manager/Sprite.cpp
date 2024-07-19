#include "pch.h"
#include "Sprite.h"

namespace Engine
{
	SpriteRenderer::SpriteRenderer(Shader&& shader) : VAO(0) 
	{ 
		this->spriteShader = shader; 
		spriteShader.use();
		spriteShader.setInt("sprite", 0);
		this->init(); 
	}

	SpriteRenderer::~SpriteRenderer() {
		glDeleteVertexArrays(1, &this->VAO);
	}

	void SpriteRenderer::DrawSprite(Texture2D& texture,
		glm::vec2 position,
		glm::vec2 size,
		glm::vec4 color) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		this->spriteShader.use();
		glm::mat4 transform(1.0f);
		transform = glm::translate(transform, glm::vec3(position, 0.0f));
		transform = glm::scale(transform, glm::vec3(size,1.0f));

		this->spriteShader.setMatrix4F("transform", transform);
		this->spriteShader.setVector4F("spriteColor", color);
		glActiveTexture(GL_TEXTURE0);
		texture.Bind();
		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_BLEND);
	}

	void SpriteRenderer::init() {
		GLuint VBO, EBO;
		float vertices[] = {
			 1.0f,  1.0f, 0.0f,  // top right
			 1.0f, -0.0f, 0.0f,  // bottom right
			-0.0f, -0.0f, 0.0f,  // bottom left
			-0.0f,  1.0f, 0.0f   // top left 
		};
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}

}
