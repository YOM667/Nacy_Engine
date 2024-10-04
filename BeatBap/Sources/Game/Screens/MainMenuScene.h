#pragma once
#include <NacyEngine.h>
#include "GameScene.h"

static int playButtonPoint = 0;
static int optionButtonPoint = 0;
static bool isExit = false;

class MainMenuScene : public Nacy::Scene {
public:
	MainMenuScene() : Nacy::Scene(1) {
		this->playButton = std::make_unique<Animator>(SECOND(0.25f), Easing::EaseInOutQuad,40.0f);
		this->optionButton = std::make_unique<Animator>(SECOND(0.25f), Easing::EaseInOutQuad, 40.0f);
	}
    void DrawBackground() override {
		if (isExit) {
			return;
		}
		// BackGround
		Nacy::Graphic::DrawRect(
			Nacy::Vector2(0, 0),
			Nacy::Vector2(this->screenWidth, this->screenHeight),
			Nacy::RGBA(0.0f, 0.0f, 0.0f, 255.0f),
			1.0f
		);
		// Continer
		Nacy::Graphic::DrawRoundedRect(
			Nacy::Vector2(200.0f, 200.0f),
			Nacy::Vector2(this->screenWidth - 400.0f, 390.0f),
			0.5f,
			Nacy::RGBA(100.0f, 100.0f, 100.0f, 255.0f),
			1.0f
		);
		// Play Button
		Nacy::Graphic::DrawRoundedRect(
			Nacy::Vector2(300.0f - playButtonPoint, 290.0f - (playButtonPoint / 8.0f)),
			Nacy::Vector2(300.0f + (playButtonPoint * 2), 100.0f + (playButtonPoint / 4.0f)),
			0.5f,
			Nacy::RGBA(230.0f, 140.0f, 180.0f, 255.0f),
			1.0f
		);
		//Option Button
		Nacy::Graphic::DrawRoundedRect(
			Nacy::Vector2(300.0f - optionButtonPoint, 420.0f - (optionButtonPoint / 8.0f)),
			Nacy::Vector2(300.0f + (optionButtonPoint * 2), 100.0f + optionButtonPoint / 4.0f),
			0.5f,
			Nacy::RGBA(230.0f, 140.0f, 180.0f, 255.0f),
			1.0f
		);
		// Title
		Nacy::Graphic::DrawCenteredText(
			"ditty_big",
			"Beat Bap",
			Nacy::Vector2(this->screenWidth / 2.0f, 80.0f),
			Nacy::RGBA(255.0f, 255.0f, 255.0f, 255.0f),
			1.0f
		);
		// Play Button Text
		Nacy::Graphic::DrawCenteredText(
			"comici_small",
			"Play",
			Nacy::Vector2(450.0f, 320.0f),
			Nacy::RGBA(255.0f, 255.0f, 255.0f, 255.0f),
			1.0f
		);
		// Options Button Text
		Nacy::Graphic::DrawCenteredText(
			"comici_small",
			"Options",
			Nacy::Vector2(450.0f, 450.0f),
			Nacy::RGBA(255.0f, 255.0f, 255.0f, 255.0f),
			1.0f
		);

    }
	void Update(double delta) override {
		if (isExit) {
			return;
		}
		if (isHovered(Nacy::Vector2( 300.0f,290.0f ), Nacy::Vector2(300.0f, 100.0f ))) {
			playButton->ChangeDirection(Direction::FORWARD);
			playButtonPoint = playButton->GetPoint();
		}
		else {
			if (!playButton->HasFinished(Direction::BACK)) {
				playButton->ChangeDirection(Direction::BACK);
				playButtonPoint = playButton->GetPoint();
			}

		}
		if (isHovered(Nacy::Vector2(300.0f, 420.0f), Nacy::Vector2(300.0f, 100.0f))) {
			optionButton->ChangeDirection(Direction::FORWARD);
			optionButtonPoint = optionButton->GetPoint();
		}
		else {
			if (!optionButton->HasFinished(Direction::BACK)) {
				optionButton->ChangeDirection(Direction::BACK);
				optionButtonPoint = optionButton->GetPoint();
			}
		}
	}
	void OnMouseButton(int button) override {
		if (isHovered(Nacy::Vector2(300.0f, 290.0f), Nacy::Vector2(300.0f, 100.0f))) {
			isExit = true;
			Nacy::SceneManager::GetInstance()->DisplayScene(new GameScene);
		}
		if (isHovered(Nacy::Vector2(300.0f, 420.0f), Nacy::Vector2(300.0f, 100.0f))) {
		}

	}

private:
	std::unique_ptr<Animator> playButton;
	std::unique_ptr<Animator> optionButton;
};