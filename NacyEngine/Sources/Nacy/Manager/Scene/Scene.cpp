#include "pch.h"
#include "Scene.h"

#include "Nacy/Util/Utilities.h"
#include "Nacy/Object/Components/Game/SpriteComponent.hpp"
#include "Nacy/Object/Components/Game/TransformComponent.hpp"
#include "Nacy/Object/Components/Interface/TextLableComponent.hpp"
#include "Nacy/Object/Components/Interface/ShapeComponent.hpp"
namespace Nacy
{
	static long long initTime = 0;
	void Init(){}
	Scene::Scene(int id) 
		: id(id), mouseX(0.0f), mouseY(0.0f),
		screenWidth(0.0f),screenHeight(0.0f), graphic(nullptr){}
	void Scene::AddGameObject(const std::string& name, GameObject* node)
	{
		this->objects.push_back(std::make_pair(name,node));
	}

	void Scene::RemoveGameObject(const std::string& name)
	{

	}

	GameObject* Scene::GetGameObject(const std::string& name)
	{
		for (auto& object : objects)
		{
			auto obj = object.second;
			if (obj->GetName() == name)
			{
				return obj;
			}
		}
		return nullptr;
	}

	void Scene::Exit()
	{
		this->objects.clear();
	}

	void Scene::SetGraphic(Graphic* graphic)
	{
		this->graphic = graphic;
	}

	void Scene::SetWindowSize(float screenWidth, float screenHeight)
	{
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
	}

	constexpr int Scene::GetID()
	{
		return this->id;
	}

	void Scene::Render(double delta)
	{
		this->DrawBackground();
		for (auto& object : this->objects)
		{
			auto obj = object.second;
			
			auto shapeRender = this->graphic->shape;
			auto spriteRender = this->graphic->sprite;
			auto fontRender = this->graphic->text;

			auto transform = obj->GetComponent<TransformComponent>();
			auto sprite = obj->GetComponent<SpriteComponent>();
			auto text = obj->GetComponent<TextLableComponent>();
			auto shape = obj->GetComponent<ShapeComponent>();
			if (shape != nullptr)
			{
				switch (shape->shapeType)
				{
				case ShapeType::Rectangle:

					shapeRender->DrawRoundedRect(transform->position.x, 
						transform->position.y,
						transform->size.x,
						transform->size.y,
						shape->radius,
						shape->color,
					1.0f);
					break;
				case ShapeType::RoundRectangle:
					shapeRender->DrawRect(transform->position.x,
						transform->position.y,
						transform->size.x,
						transform->size.y,
						shape->color,
						1.0f);
					break;
				}
			}
			if (sprite != nullptr)
			{
				
				spriteRender->DrawSprite(sprite->texture,
					transform->position.x, transform->position.y,
					transform->size.x, transform->size.y,
					sprite->color);
			}
			if (text != nullptr)
			{
				if (text->centered)
				{
					fontRender->GetFont(text->font).RenderText(
							text->text,
							transform->position.x, transform->position.y,
							1.0f,
							text->color
						);
				}
				else
				{
					fontRender->GetFont(text->font).RenderCenterdText(
							text->text,
							transform->position.x, transform->position.y,
							1.0f,
							text->color
						);
				}
				
			}
		}
	}
}