#pragma once
#include <NacyEngine.h>
#include "Screens/MenuScreen.h"
#include "Renderer/BackgroundRenderer.hpp"
class BeatBap : public Engine::NApplication
{
public:
	BeatBap() : NApplication(this->createWindow({ "BeatBap", true, 1270, 800, true, false }))
	{
		if (glewInit() != GLEW_OK) glfwTerminate();
		this->GetGraphic()->text->load("Resources/Fonts/CoffeeHealing-1GrKe.ttf", 64,"coffee");
		this->GetGraphic()->text->load("Resources/Fonts/Ditty-Rp72W.ttf", 48, "ditty");

		auto background = Engine::ResourceManager::LoadShaderFromFile("Resources/Shaders/background.vs","Resources/Shaders/background.fs","background");
		background.useShader().setMatrix4F("projection", this->window->GetProjection());

		this->render = std::make_shared<BackgroundRenderer>(background);

		this->displayScreen(new MenuScreen());
	}
	~BeatBap()
	{
		this->window->destory();
	}

	static std::shared_ptr<BeatBap> GetInstance()
	{
		static const std::shared_ptr<BeatBap> beatbap = std::make_shared<BeatBap>();
		return beatbap;
	}
	std::shared_ptr<BackgroundRenderer> getBackground()
	{
		return this->render;
	}
	
private:
	std::shared_ptr<BackgroundRenderer> render;
};
