#include "BeatBap.h"

#include "SoundEngine/SoundEngine.h"
#include "Screens/SplashScene.hpp"
Nacy::Application* BeatBap::app = nullptr;

void BeatBap::Init()
{
	auto app = GetApplication();
	Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Engine x Start!!.png", true, "music_background");
	Nacy::ResourceManager::LoadTexture2D("Resources/Textures/click.png", true, "click");
	Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Engine x Start!!-logo.png", true, "logo");

	Nacy::ResourceManager::LoadFont("Resources/Fonts/CoffeeHealing-1GrKe.ttf", 64, "coffee");
	Nacy::ResourceManager::LoadFont("Resources/Fonts/CoffeeHealing-1GrKe.ttf", 28, "little_coffee");
	Nacy::ResourceManager::LoadFont("Resources/Fonts/Ditty-Rp72W.ttf", 48, "ditty");

	Nacy::ResourceManager::LoadShaderFromFile("Resources/Shaders/background.vs", "Resources/Shaders/background.fs", "background")
		.UseShader().SetMatrix4F("projection", app->GetWindow()->GetProjection());
	
	
	SoundEngine::GetInstance()->LoadSound("music", Sound("Resources/Audio/music.ogg",true));

	SoundEngine::GetInstance()->LoadSound("Engine x Start", Sound("Resources/Audio/CrossingSound - Engine x Start!! (melody mix).ogg", false));

	Nacy::SceneManager::GetInstance()->DisplayScene(new SplashScene());

}

void BeatBap::Run()
{
	GetApplication()->Start();
}

void BeatBap::Stop()
{
	GetApplication()->ShutDown();
}
