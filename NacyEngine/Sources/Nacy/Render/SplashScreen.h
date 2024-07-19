#pragma once
#include "Screen.h"
#include "Nacy/Utilities.h"

using namespace Utilities;
namespace Engine
{
	class SplashScreen : public Engine::Screen
	{
	public:
		SplashScreen();
		void LoadingText(double delta);
		void render(double delta) override;

		bool isFinished();
		
	private:
		std::unique_ptr<Animation::Animator> animator;
		Engine::Texture2D texture;

		bool finished;
		double alpha;
		double scale = 0.0f;
		int64_t initTime = 0LL;
	};
}


