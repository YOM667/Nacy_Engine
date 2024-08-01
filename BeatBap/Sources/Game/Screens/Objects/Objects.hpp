#pragma once
#include <NacyEngine.h>

class BarLineObject : public Nacy::GameObject
{
public:
	BarLineObject(int index) : Nacy::GameObject("BarLine")
	{
		auto transform = this->GetComponent<Nacy::TransformComponent>();
		transform->position.x = 220.0f + index * 210.0f;
		transform->position.y = 0.0f;
		transform->size.x = 4.0f;
		transform->size.y = 1270.0f;
		this->AddComponent(new Nacy::ShapeComponent(Nacy::RGBA(92.0f, 92.0f, 92.0f, 255.0f), Nacy::ShapeType::RECTANGLE));
	}
};
class CheckLineNode : public Nacy::GameObject
{
public:
	CheckLineNode(int index) : Nacy::GameObject("CheckLine")
	{
		auto transform = this->GetComponent<Nacy::TransformComponent>();
		transform->position.x = 225.0f + index * 210.0f;
		transform->position.y = 600.0f;
		transform->size.x = 200.0f;
		transform->size.y = 5.0f;
		this->AddComponent(new Nacy::ShapeComponent(Nacy::RGBA(255.0f), Nacy::ShapeType::ROUND_RECTANGLE));
	}
};
class BeatObject : public Nacy::GameObject
{
public:
	// 200 0 190 20
	BeatObject(int index, double ms, uint64_t delay) : Nacy::GameObject("Beat")
	{
		auto click = Nacy::ResourceManager::GetTexture2D("click");
		auto transform = this->GetComponent<Nacy::TransformComponent>();
		transform->position.x = 220.0f + index * 210.0f + 10.0f;
		transform->position.y = -20.0f;
		transform->size.x = 190.0f;
		transform->size.y = 20.0f;
		this->AddComponent(new Nacy::SpriteComponent(click));
		//this->AddComponent(new Nacy::DelayComponent(delay));
	}
private:
	Nacy::Texture2D texture;
	
};
