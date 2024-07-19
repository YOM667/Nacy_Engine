#include "MenuScreen.h"

#include "../BeatBap.hpp"
#include "GameScene.hpp"
static bool pressed = false;
static double alpha = 0.0;

MenuScreen::MenuScreen() : Screen(2)
{
	this->background = Engine::ResourceManager::GetTexture2D("background");
	this->animator = std::make_unique<Animation::Animator>(4, Animation::Easing::Linear, 0.0, 255.0);
}
void MenuScreen::render(double delta)
{
	if (alpha != 255.0)
	{
		alpha = this->animator->getPoint(delta);
	}
	BeatBap::GetInstance()->getBackground()->draw(glm::vec2(0, 0), glm::vec2(1270, 800), Utilities::Time::getGLFWTime(), alpha / 255.0);
	this->graphic->text->getFont("ditty").renderCenterdText("Press any key to start the game", screenWidth / 2.0f, 600, 1.0f, glm::vec4(1.0f, 1.0f, 1.0f, alpha / 255.0));

	if (pressed)
	{
		if (this->animator->getDirection() != Animation::Direction::BACK)
		{
			this->animator->changeDirection(Animation::Direction::BACK);
		}
		if (alpha >= 0)
		{
			alpha = this->animator->getPoint(delta);
		}
		if (alpha <= 0)
		{
			BeatBap::GetInstance()->displayScene(new GameScene());
		}
	}
}
void MenuScreen::keyPressed(int keyCode)
{
	if (!pressed) pressed = true;
}



