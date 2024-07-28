#include "pch.h"

#include "Shape.h"

#include "Nacy/Manager/Assets/ResourceManager.h"
namespace Nacy
{
	ShapeRenderer::ShapeRenderer()
	{
        this->rectRenderer = new Renderer(ResourceManager::GetShader("rectShader"));
		this->roundedRectRenderer = new Renderer(ResourceManager::GetShader("roundedRectShader"));
		this->roundedRectOutlinRenderer = new Renderer(ResourceManager::GetShader("roundedRectOutlineShader"));
	}

	ShapeRenderer::~ShapeRenderer()
	{
	}

	void ShapeRenderer::DrawRect(float x, float y, float width, float height, const RGBA& color, float scale)
	{
		rectRenderer->x = x;
		rectRenderer->y = y;
		rectRenderer->width = width;
		rectRenderer->height = height;
		this->rectRenderer->GetShader().Use();
		this->rectRenderer->GetShader().SetVector4F("rectColor", glm::vec4(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha / 255.0f));
		this->rectRenderer->Draw();
	}
	void ShapeRenderer::DrawRoundedRect(float x, float y, float width, float height, float radius, const RGBA& color, float scale)
	{
		roundedRectRenderer->x = x;
		roundedRectRenderer->y = y;
		roundedRectRenderer->width = width;
		roundedRectRenderer->height = height;
		roundedRectRenderer->scale = scale;
		this->roundedRectRenderer->GetShader().Use();
		this->roundedRectRenderer->GetShader().SetVector3F("rectColor", glm::vec4(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha / 255.0f));
		this->roundedRectRenderer->GetShader().SetFloat("alpha", color.alpha / 255.0f);
		this->roundedRectRenderer->GetShader().SetFloat("radius", radius);
		this->roundedRectRenderer->GetShader().SetVector2F("size", glm::vec2(width, height));
		this->roundedRectRenderer->Draw();
	}
	void ShapeRenderer::DrawRoundedRectOutline(float x, float y, float width, float height, float radius, float outlineThickness, const RGBA& outlineColor, const RGBA& internalColor, float scale)
	{
		roundedRectOutlinRenderer->x = x;
		roundedRectOutlinRenderer->y = y;
		roundedRectOutlinRenderer->width = width;
		roundedRectOutlinRenderer->height = height;
		roundedRectOutlinRenderer->scale = scale;
		this->roundedRectOutlinRenderer->GetShader().Use();
		this->roundedRectOutlinRenderer->GetShader().SetVector4F("rectColor", glm::vec4(internalColor.red / 255.0f, internalColor.green / 255.0f, internalColor.blue / 255.0f, internalColor.alpha / 255.0f));
		this->roundedRectOutlinRenderer->GetShader().SetVector4F("outlineColor", glm::vec4(outlineColor.red / 255.0f, outlineColor.green / 255.0f, outlineColor.blue / 255.0f, outlineColor.alpha / 255.0f));
		this->roundedRectOutlinRenderer->GetShader().SetVector2F("size", glm::vec2(width, height));\
		this->roundedRectOutlinRenderer->GetShader().SetVector2F("location", glm::vec2(x, (800 - height) - y));
		this->roundedRectOutlinRenderer->GetShader().SetFloat("thickness", outlineThickness);
		this->roundedRectOutlinRenderer->GetShader().SetFloat("radius", radius);
		this->roundedRectOutlinRenderer->Draw();
	}
}