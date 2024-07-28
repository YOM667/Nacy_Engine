#include "pch.h"
#include "Sprite.h"

#include "Nacy/Manager/Assets/ResourceManager.h"
namespace Nacy
{
	
	SpriteRenderer::SpriteRenderer()
	{ 
		this->spriteRenderer = new Renderer(Nacy::ResourceManager::GetShader("textureShader"));
		this->spriteRoundRenderer = new Renderer(Nacy::ResourceManager::GetShader("roundTextureShader"));
		this->spriteRenderer->GetShader().UseShader().SetInt("sprite", 0);
		this->spriteRoundRenderer->GetShader().UseShader().SetInt("sprite", 0);

	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::DrawSprite(Texture2D& texture, float x, float y, float width, float height, const RGBA& color)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glm::mat4 transform(1.0f);
		this->spriteRenderer->GetShader().Use();
		transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
		transform = glm::scale(transform, glm::vec3(width, height, 1.0f));
		this->spriteRenderer->GetShader().SetMatrix4F("transform", transform);
		this->spriteRenderer->GetShader().SetVector4F("spriteColor", glm::vec4(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha / 255.0f));

		glActiveTexture(GL_TEXTURE0);
		texture.Bind();
		glBindVertexArray(this->spriteRenderer->GetVAO());
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_BLEND);


	}

	void SpriteRenderer::DrawRoundedSprite(Texture2D& texture, float x, float y, float width, float height, float radius, float scale, const RGBA& color)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glm::mat4 transform(1.0f);
		this->spriteRoundRenderer->GetShader().Use();
		transform = glm::translate(transform, glm::vec3(x, y, 0.0f));

		transform = glm::translate(transform, glm::vec3(0.5f * (width), 0.5f * (height), 0.0f));
		transform = glm::scale(transform, glm::vec3(scale, scale, 1.0f));
		transform = glm::translate(transform, glm::vec3(-0.5f * (width), -0.5f * (height), 0.0f));

		transform = glm::scale(transform, glm::vec3(width, height, 1.0f));


		this->spriteRoundRenderer->GetShader().SetMatrix4F("transform", transform);
		this->spriteRoundRenderer->GetShader().SetVector3F("spriteColor", glm::vec3(color.red / 255.0f, color.green / 255.0f,color.blue / 255.0f));
		this->spriteRoundRenderer->GetShader().SetVector2F("size", glm::vec2(width,height));
		this->spriteRoundRenderer->GetShader().SetFloat("alpha", color.alpha / 255.0f);
		this->spriteRoundRenderer->GetShader().SetFloat("radius", radius);

		glActiveTexture(GL_TEXTURE0);
		texture.Bind();
		glBindVertexArray(this->spriteRoundRenderer->GetVAO());
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_BLEND);
	}
	
}
