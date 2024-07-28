#pragma once

#include <NacyEngine.h>
#include "MenuScene.hpp"

using namespace Utility;

class SplashScene : public Nacy::Scene
{
public:
	SplashScene()
		: Scene(0), alpha(0.0f), initTime(GetNowTime())
	{
		this->animator = new Animator(2, Easing::EaseInQuad, 0.0, 255.0);
		this->texture = Nacy::ResourceManager::GetTexture2D("nacy");
	}
	void Init()
	{
		//======Logo======
		auto logo = new Nacy::GameObject("Logo");

		logo->GetComponent<Nacy::TransformComponent>()->position.x = (this->screenWidth - 256) / 2.0f;
		logo->GetComponent<Nacy::TransformComponent>()->position.y = 200.0f;
		logo->GetComponent<Nacy::TransformComponent>()->size.x = 256.0f;
		logo->GetComponent<Nacy::TransformComponent>()->size.y = 256.0f;

		logo->AddComponent(new Nacy::SpriteComponent(texture, Nacy::RGBA(255.0f, 255.0f, 255.0f, 0.0f)));

		this->AddGameObject("Logo", logo);
		//======Text======
		auto text = new Nacy::GameObject("Text");

		text->GetComponent<Nacy::TransformComponent>()->position.x = this->screenWidth / 2.0f;
		text->GetComponent<Nacy::TransformComponent>()->position.y = 480;

		text->AddComponent(new Nacy::TextLableComponent("Made by Nacy", "comici", Nacy::RGBA(255.0f, 142.8f, 137.0f, alpha)));

		this->AddGameObject("Text", text);
	}

	void Update(double delta)
	{
		auto time = GetNowTime();
		auto finished = time - initTime >= 4000000000;
		if (finished)
		{
			Nacy::SceneManager::GetInstance()->DisplayScene(new MenuScene);
			return;
		}
		if (animator->GetDirection() != Direction::BACK)
		{
			if (alpha < 255.0)
			{
				alpha = animator->GetPoint(delta);
			}
			else
			{
				this->animator->ChangeDirection(Direction::BACK);
			}
		}
		else if (animator->GetDirection() != Direction::FORWARD)
		{
			if (alpha > 0.0)
			{
				alpha = animator->GetPoint(delta);
			}
			else
			{
				this->animator->ChangeDirection(Direction::FORWARD);
			}
		}
		this->GetGameObject("Logo")->GetComponent<Nacy::SpriteComponent>()->color.alpha = alpha;
		this->GetGameObject("Text")->GetComponent<Nacy::TextLableComponent>()->color.alpha = alpha;
	}
private:
	Animator* animator;
	Nacy::Texture2D texture;
	double alpha;
	uint64_t initTime;
};


