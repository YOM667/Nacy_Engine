#pragma once

#include <NacyEngine.h>
using namespace Utilities;
class MenuScreen : public Engine::Screen
{
public:
	MenuScreen();
	void render(double delta) override;
	void keyPressed(int keyCode) override;
private:
	std::unique_ptr<Animation::Animator> animator;
	Engine::Texture2D background;
};


