#pragma once

#include <NacyEngine.h>
class GameOverScene : public Nacy::Scene{
public:
	GameOverScene() : Scene(3) {

	}

	void DrawBackground() override {
		Nacy::Graphic::DrawRect(
			Nacy::Vector2(0, 0),
			Nacy::Vector2(this->screenWidth, this->screenHeight),
			Nacy::RGBA(0.0f, 0.0f, 0.0f, 255.0f),
			1.0f
		);
	}

};