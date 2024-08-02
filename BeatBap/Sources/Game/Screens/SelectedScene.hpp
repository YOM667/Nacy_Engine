#pragma once
#include <NacyEngine.h>
#include "GameScene.hpp"
#include "SettingScene.hpp"
class SelectedScene : public Nacy::Scene
{
public:
	SelectedScene() : Nacy::Scene(4), scale(100.0f), isScale(false), current(-1)
	{
		this->animator = new Utility::Animator(1.0f,Utility::Easing::Linear,100.0f,107.0f);
		this->animator->ChangeDirection(Utility::Direction::BACK);
	}
	void Init() override
	{
		this->Clear();
		auto sheet = new Nacy::GameObject("Sheet");
		auto sheetTransform = sheet->GetComponent<Nacy::TransformComponent>();
		auto sheetTexture = Nacy::ResourceManager::GetTexture2D("logo");
		sheetTransform->position.x = -20.0f;
		sheetTransform->position.y = 300.0f;
		sheetTransform->size.x = 400.0f;
		sheetTransform->size.y = 66.6f;
		sheetTransform->scale = scale / 100.0f;
		sheet->AddComponent(new Nacy::SpriteComponent(sheetTexture, Nacy::RGBA(255.0f), Nacy::SpriteType::ROUND, 10.0f));
		this->AddGameObject("Sheet", sheet);

		auto setting = new Nacy::GameObject("Setting");
		auto settingTransform = setting->GetComponent<Nacy::TransformComponent>();
		auto settingTexture = Nacy::ResourceManager::GetTexture2D("setting");
		settingTransform->position.x = 20.0f;
		settingTransform->position.y = 10.0f;
		settingTransform->size.x = 40.0f;
		settingTransform->size.y = 40.0f;
		setting->AddComponent(new Nacy::SpriteComponent(settingTexture, Nacy::RGBA(255.0f)));
		this->AddGameObject("Setting", setting);
	}
	void DrawBackground() override
	{
		auto texture = Nacy::ResourceManager::GetTexture2D("music_background");
		if (current == 0)
		{
			this->graphic->sprite->DrawSprite(texture, 0, 0, this->screenWidth, this->screenHeight, Nacy::RGBA(255.0f));
			this->graphic->shape->DrawRect(0, 0, this->screenWidth, this->screenHeight, Nacy::RGBA(0.0f, 0.0f, 0.0f, 200.0f), 1.0f);
		}
		
		
		this->graphic->shape->DrawRect(0, 0, 80, 80, Nacy::RGBA(0.0f, 0.0f, 0.0f, 150.0f), 1.0f);
		this->graphic->text->GetFont("comici_20").RenderCenterdText("Setting", 40.0f, 55.0f, 1.0f, Nacy::RGBA(255.0f));
	}

	void Update(double delta) override
	{
		auto mouseX = Nacy::InputManager::mouseX;
		auto mouseY = Nacy::InputManager::mouseY;
		auto transform = this->GetGameObject("Sheet")->GetComponent<Nacy::TransformComponent>();

		this->isScale = this->isHovered(transform, mouseX, mouseY);
		
		
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
		transform->scale = this->scale / 100.0f;
	}
	void OnMouseButton(int button) override
	{
		auto sheetTransform = this->GetGameObject("Sheet")->GetComponent<Nacy::TransformComponent>();
		auto settingTransform = this->GetGameObject("Setting")->GetComponent<Nacy::TransformComponent>();
		auto mouseX = Nacy::InputManager::mouseX;
		auto mouseY = Nacy::InputManager::mouseY;
		if (button == Nacy::LEFT_BUTTON)
		{
			if (this->isHovered(sheetTransform, mouseX, mouseY))
			{
				this->current = 0;

			}
			else if (this->isHovered(settingTransform, mouseX, mouseY))
			{
				Nacy::SceneManager::GetInstance()->DisplayScene(new SettingScene);
			}
		}

	}
private:
	int current;
	bool playHover = false;
	bool isScale;
	float scale;
	Utility::Animator* animator;
};

