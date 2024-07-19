#include "pch.h"
#include "SplashScreen.h"
#include "Nacy/Manager/ResourceManager.h"
#include "Nacy/Core/NApplication.h"
namespace Engine
{
	SplashScreen::SplashScreen() : Screen(0)
	{
		this->animator = std::make_unique<Animation::Animator>(2, Animation::Easing::EaseInQuad, 0.0, 255.0);
		this->texture = Engine::ResourceManager::GetTexture2D("nacy");
		initTime = Time::getNowTime();
	}
	void SplashScreen::LoadingText(double delta)
	{
		if (animator->getDirection() != Animation::Direction::BACK)
		{
			if (alpha < 255)
			{
				alpha = animator->getPoint(delta);
			}
			else
			{
				this->animator->changeDirection(Animation::Direction::BACK);
			}
		}
		else if (animator->getDirection() != Animation::Direction::FORWARD)
		{
			if (alpha > 0)
			{
				alpha = animator->getPoint(delta);
			}
			else
			{
				this->animator->changeDirection(Animation::Direction::FORWARD);
			}
		}
		this->graphic->sprite->DrawSprite(texture, { (this->screenWidth - 256) / 2.0f,200 }, { 256,256 }, glm::vec4(1.0, 1.0, 1.0, alpha / 255.0));
		this->graphic->text->getFont("comici").renderCenterdText("Made by Nacy", this->screenWidth / 2.0f, 480, 1.0f, glm::vec4(1.0f, 0.561, 0.549, alpha / 255.0f));
	}

	void SplashScreen::render(double delta)
	{
		auto time = Time::getNowTime();
		this->finished = time - initTime >= 4000000000;
		if (finished)
		{
			return;
		}
		this->LoadingText(delta);
	}
	bool SplashScreen::isFinished()
	{
		return this->finished;
	}
}