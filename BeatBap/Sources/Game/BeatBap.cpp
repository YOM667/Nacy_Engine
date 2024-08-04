#include "BeatBap.h"

#include "SoundEngine/SoundEngine.h"
#include "Screens/SplashScene.hpp"

Nacy::Application *BeatBap::app = nullptr;

void BeatBap::Init() {
    auto application = GetApplication();
    auto sceneManager = Nacy::SceneManager::GetInstance();
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Engine x Start!!.png", true, "music_background");
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/click.png", true, "click");
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Engine x Start!!-logo.png", true, "logo");
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/setting.png", true, "setting");
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/back.png", true, "back");

    Nacy::ResourceManager::LoadFont("Resources/Fonts/Ditty-Rp72W.ttf", 48, "ditty");
    Nacy::ResourceManager::LoadFont("Resources/Fonts/Ditty-Rp72W.ttf", 64, "ditty_big");

    Nacy::ResourceManager::LoadShaderFromFile("Resources/Shaders/background.vs", "Resources/Shaders/background.fs",
                                              "background").UseShader().SetMatrix4F("projection",
                                                                                    application->GetWindow()->GetProjection());

    SoundEngine::GetInstance()->LoadSound("hover", Sound("Resources/Audio/hover.wav", false));
    SoundEngine::GetInstance()->LoadSound("music", Sound("Resources/Audio/music.ogg", true));
    SoundEngine::GetInstance()->LoadSound("Engine x Start",
                                          Sound("Resources/Audio/CrossingSound - Engine x Start!! (melody mix).ogg",
                                                false));
    sceneManager->DisplayScene(new SplashScene());
    auto esc = Nacy::KeyBinding(256, Nacy::KeyConflit::IN_GAME, [application](auto action) {
        switch (action) {
            case Nacy::KeyActionType::KEY_PRESSED:
                application->ShutDown();
                break;
            default:
                break;
        }
    });
    Nacy::InputManager::RegisterKeyBinding("exit", esc);

}

void BeatBap::Run() {
    GetApplication()->Start();
}

void BeatBap::Stop() {
    GetApplication()->ShutDown();
}
