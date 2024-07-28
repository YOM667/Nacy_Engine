#pragma once
#include <NacyEngine.h>
#include "GameScene.hpp"

class SelectedScene : public Nacy::Scene
{
public:
	SelectedScene() : Nacy::Scene(4), scale(100.0f), isScale(false)
	{
		animator = new Utility::Animator(1.0f,Utility::Easing::Linear,100.0f,107.0f);
		this->animator->ChangeDirection(Utility::Direction::BACK);
	}
	void Init() override
	{
		auto sheet = new Nacy::GameObject("Sheet");
		auto transform = sheet->GetComponent<Nacy::TransformComponent>();

		transform->position.x = -20.0f;
		transform->position.y = -300.0f;
		transform->size.x = 600.0f;
		transform->size.y = 100.0f;
		transform->scale = this->scale / 100.0f;
		this->AddGameObject("Sheet", sheet);
	}
	void DrawBackground() override
	{
		this->graphic->shape->DrawRect(0, 0, this->screenWidth, this->screenHeight, Nacy::RGBA(92.0f,92.0f,92.0f,255.0f), 1.0f);
	}

	void Update(double delta) override
	{
		if (isScale)
		{
			if (this->animator->GetDirection() != Utility::Direction::FORWARD)
			{
				this->animator->ChangeDirection(Utility::Direction::FORWARD);
			}
			this->scale = this->animator->GetPoint(delta);
		}
		else
		{
			if (this->animator->GetDirection() != Utility::Direction::BACK)
			{
				this->animator->ChangeDirection(Utility::Direction::BACK);
			}
			this->scale = this->animator->GetPoint(delta);
		}
		this->GetGameObject("Sheet")->GetComponent<Nacy::TransformComponent>()->scale = this->scale;
	}
private:
	bool playHover = false;
	bool isScale;
	float scale;
	Utility::Animator* animator;
};

