#pragma once
#include <NacyEngine.h>
#include "SoundEngine/SoundEngine.h"
#include "Renderer/BGRenderer.hpp"
#include "SelectedScene.hpp"
class MenuScene : public Nacy::Scene
{
public:
	MenuScene()
		: Scene(2), pressed(false), alpha(0.0)
	{
		this->background = std::make_unique<BGRenderer>();
		this->animator = std::make_unique<Utility::Animator>(4.0, Utility::Easing::EaseInQuad, 0.0, 255.0);
	}
	void DrawBackground() override
	{
		this->background->Draw(0,0, this->screenWidth, this->screenHeight, this->alpha);
	}

	void Init() override
	{
		SoundEngine::GetInstance()->NPlaySound("music");

		auto text = new Nacy::GameObject("Text");
		auto transform = text->GetComponent<Nacy::TransformComponent>();
		transform->position.x = screenWidth / 2.0f;
		transform->position.y = 600;
		text->AddComponent(new Nacy::TextLableComponent("---[ Press any key to start the game ]---","ditty",Nacy::RGBA(255.0f, 255.0f, 255.0f, 0.0f)));
		this->AddGameObject("Text",text);

		auto enter = Nacy::KeyBinding([this](auto action)
			{
				switch (action)
				{
				case Nacy::KeyActionType::KEY_PRESSED:
					pressed = true;
					break;
				}
			});
		Nacy::InputManager::RegisterKeyBinding("enter", enter);
	}

	void Update(double delta) override
	{
		if (alpha <= 255.0)
		{
			alpha = this->animator->GetPoint(delta);
		}
		if (pressed)
		{
			if (this->animator->GetDirection() != Utility::Direction::BACK)
			{
				this->animator->ChangeDirection(Utility::Direction::BACK);
			}
			if (alpha >= 0)
			{
				alpha = this->animator->GetPoint(delta);
			}
			if (alpha <= 0)
			{
				SoundEngine::GetInstance()->StopSounds();
				Nacy::SceneManager::GetInstance()->DisplayScene(new SelectedScene());
			}
		}
		this->GetGameObject("Text")->GetComponent<Nacy::TextLableComponent>()->color.alpha = alpha;
		//TODO keypressed 
	}
private:
	std::unique_ptr<Utility::Animator> animator;
	std::unique_ptr<BGRenderer> background;
	bool pressed;
	float alpha;

};


