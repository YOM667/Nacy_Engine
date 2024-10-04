#pragma once

#include <NacyEngine.h>
#include "Util.hpp"
#include "MainMenuScene.h"
using namespace Utility;


static uint64_t init_time = 0.0f;

class SplashScene : public Nacy::Scene {
public:
    SplashScene() : Scene(0) {
        this->animator = std::make_unique<Animator>(SECOND(1.5f), Easing::Smooth, 255.0);
        init_time = GetMillsTime();
    }
    void DrawBackground() override {
        Nacy::Graphic::DrawSprite(Nacy::ResourceManager::GetTexture2D("nacy"),
                       Nacy::Vector2((this->screenWidth - 256.0f) / 2.0f, this->screenHeight / 2.0f - 150),
                       Nacy::Vector2(256.0f,256.0f),
                       Nacy::RGBA(255.0f, 255.0f, 255.0f, alpha));
        Nacy::Graphic::DrawCenteredText("comici", 
                       "Made by Nacy",
                       Nacy::Vector2(this->screenWidth / 2.0f,this->screenHeight / 2.0f + 150),
                       Nacy::RGBA(255.0f, 142.8f, 137.0f, alpha),
                       1.0f);
    }
    void Init() override {
        this->Clear();
    }

    void Update(double delta) override {
        auto time = GetMillsTime();
        auto finished = (time - init_time >= SECOND(3.0f));
        if (finished) {
            Nacy::SceneManager::GetInstance()->DisplayScene(new MainMenuScene());
            return;
        }
        if (animator->GetDirection() != Direction::BACK) {
            if (alpha < 255.0f) {
                alpha = animator->GetPoint();
            }
            else {
                animator->ChangeDirection(Direction::BACK);
            }
        } else if (animator->GetDirection() != Direction::FORWARD) {
            if (alpha > 0.0f) {
                alpha = animator->GetPoint();
            }
            else {
                animator->ChangeDirection(Direction::FORWARD);
            }
        }
    }
private:
    float alpha = 0.0f;
    std::unique_ptr<Animator> animator;
};


