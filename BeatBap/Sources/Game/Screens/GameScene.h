#pragma once
#include <NacyEngine.h>
#include "Util.hpp"
#include "GameOverScene.h"
#include "Game/System/MineSweepSystem.h"

static bool start = false;
class GameScene : public Nacy::Scene {
public:
	GameScene() : Nacy::Scene(2) {
		this->animator = std::make_unique<Animator>(SECOND(1.5f), Easing::Smooth, 255.0);
		this->system = std::make_unique<System::MineSweepSystem>();
		this->system->InitMap();
		this->alpha = 0.0f;
	}

	void Init() override {
		this->Clear();
	}
	void DrawBackground() override {
		// BackGround
		Nacy::Graphic::DrawRect(
			Nacy::Vector2(0, 0),
			Nacy::Vector2(this->screenWidth, this->screenHeight),
			Nacy::RGBA(230.0f, 230.0f, 200.0f, alpha),
			1.0f
		);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {

				if (System::map[i][j].isOpened) {
					auto texture = (System::map[i][j].value == -1
						? Nacy::ResourceManager::GetTexture2D("mine") : Nacy::ResourceManager::GetTexture2D("empty"));
					Nacy::Graphic::DrawSprite(texture,
						Nacy::Vector2(200.0f + (j * 55.0f), 80.0f + (i * 55.0f)),
						Nacy::Vector2(50.0f, 50.0f),
						Nacy::RGBA(255.0f, 255.0f, 255.0f, alpha));
					if (System::map[i][j].value != 0 && System::map[i][j].value != -1) {
						Nacy::Graphic::DrawCenteredText("common", std::to_string(System::map[i][j].value),
							Nacy::Vector2(200.0f + (j * 55.0f) + 25.0f, 80.0f + (i * 55.0f) + 10.0f),
							Nacy::RGBA(40.0f, 40.0f, 220.0f, alpha), 1.0f);
					}
				} else {
					auto block = Nacy::ResourceManager::GetTexture2D("block");
					Nacy::Graphic::DrawSprite(block,
						Nacy::Vector2(200.0f + (j * 55.0f), 80.0f + (i * 55.0f)),
						Nacy::Vector2(50.0f, 50.0f),
						Nacy::RGBA(255.0f, 255.0f, 255.0f, alpha));
					
					if (System::map[i][j].flag) {
						Nacy::Graphic::DrawRect(
							Nacy::Vector2(200.0f + (j * 55.0f) + 20.0f, 80.0f + (i * 55.0f) + 20.0f),
							Nacy::Vector2(10.0f, 10.0f),
							Nacy::RGBA(100.0f, 100.0f, 100.0f, alpha),
							1.0f
						);
					}
					
					if (System::map[i][j].hovered) {
						Nacy::Graphic::DrawRect(
								Nacy::Vector2(200.0f + (j * 55.0f), 80.0f + (i * 55.0f)),
								Nacy::Vector2(50.0f, 50.0f),
							Nacy::RGBA(255.0f, 255.0f, 255.0f, alpha * (100.0f / 255.0f)),
								1.0f
						);
					}

				}
			}
		}

	}
	void Update(double delta) override {
		if (!start) {
			if (animator->GetDirection() != Direction::BACK) {
				if (!animator->HasFinished(Direction::FORWARD)) {
					alpha = animator->GetPoint();
				}
				else {
					start = true;
					animator->ChangeDirection(Direction::BACK);
				}
			}
		}

		

		if (System::gameOver) {
			if ((Utility::GetMillsTime() - System::initTime) >= SECOND(3.0f)) {
				if (animator->GetDirection() == Direction::BACK) {
					if (alpha > 1.0f) {
						alpha = animator->GetPoint();
					}
					else {
						animator->ChangeDirection(Direction::FORWARD);
						Nacy::SceneManager::GetInstance()->DisplayScene(new GameOverScene);
					}
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (isHovered(Nacy::Vector2(200.0f + (j * 55.0f), 80.0f + (i * 55.0f)), Nacy::Vector2(50.0f, 50.0f))) {
					System::map[i][j].hovered = true;
				}
				else {
					System::map[i][j].hovered = false;
				}
			}
		}
	}

	void OnMouseButton(int button) override {
		if (System::gameOver) return;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (isHovered(Nacy::Vector2(200.0f + (j * 55.0f), 80.0f + (i * 55.0f)), Nacy::Vector2(50.0f, 50.0f))) {
					if (button == 0) {
						system->OpenBlock(i, j);
					}
					else if(button == 1) {
						system->MarkFlag(i, j);
					}

				}
			}
		}
	}
private:
	float alpha;
	std::unique_ptr<Animator> animator;
	std::unique_ptr<System::MineSweepSystem> system;
};