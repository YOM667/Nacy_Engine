#include "BeatBap.h"

#include "SoundEngine/SoundEngine.h"
#include "Screens/SplashScene.h"

Nacy::Application *BeatBap::app = nullptr;

void BeatBap::Init() {
    auto application = GetApplication();
    auto sceneManager = Nacy::SceneManager::GetInstance();
    Nacy::ResourceManager::LoadFont("Resources/Fonts/Ditty-Rp72W.ttf", 32, "ditty");
    Nacy::ResourceManager::LoadFont("Resources/Fonts/Ditty-Rp72W.ttf", 64, "ditty_big");
    Nacy::ResourceManager::LoadFont("Resources/Fonts/trebucbd.ttf", 32, "common");

    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Block.png", false, "block");
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Empty.png", true, "empty");
    Nacy::ResourceManager::LoadTexture2D("Resources/Textures/Mine.png", false, "mine");

    SoundEngine::GetInstance()->LoadSound("hover", Sound("Resources/Audio/hover.wav", false));

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
