#pragma once 
#include <NacyEngine.h>

class GameScene : public Engine::Scene
{

	void init() override
	{
		auto beat = Engine::Node("beat", glm::vec2(10.0f, 10.0f));
		beat.addComponent(std::make_shared<Engine::SpriteComponent>("Sprite"));
		auto sprite = beat.GetComponent("sprite");
		std::cout << sprite->GetName() << std::endl;
		this->addNode("beat",beat);

	}

};
