#pragma once

#include <NacyEngine.h>
#include "MenuScene.hpp"

using namespace Utility;

class SplashScene : public Nacy::Scene {
public:
    SplashScene() : Scene(0), alpha(0.0f), initTime(GetNowTime()) {
        this->animator = new Animator(2, Easing::EaseInQuad, 0.0, 255.0);
        this->texture = Nacy::ResourceManager::GetTexture2D("nacy");
    }

    void DrawBackground() override {
        this->graphic->sprite->DrawSprite(texture,
                                          Nacy::Vector2((this->screenWidth - 256.0f) / 2.0f, this->screenHeight / 2.0f - 150),
                                          Nacy::Vector2(256.0f,256.0f),
                                          Nacy::RGBA(255.0f, 255.0f, 255.0f, this->alpha));
        this->graphic->text->GetFont("comici").RenderCenterdText("Made by Nacy",
                                                                 Nacy::Vector2(this->screenWidth / 2.0f,this->screenHeight / 2.0f + 150),
                                                                 1.0f,
                                                                 Nacy::RGBA(255.0f, 142.8f, 137.0f, this->alpha));
    }

    void Init() override {
        this->Clear();
    }

    void Update(double delta) override {
        auto time = GetNowTime();
        auto finished = time - initTime >= 3500000000;
        if (finished) {
            Nacy::SceneManager::GetInstance()->DisplayScene(new MenuScene);
            return;
        }
        if (animator->GetDirection() != Direction::BACK) {
            if (alpha < 255.0f) {
                alpha = animator->GetPoint(delta);
            } else {
                this->animator->ChangeDirection(Direction::BACK);
            }
        } else if (animator->GetDirection() != Direction::FORWARD) {
            if (alpha > 0.0f) {
                alpha = animator->GetPoint(delta);
            } else {
                this->animator->ChangeDirection(Direction::FORWARD);
            }
        }
    }

private:
    Animator *animator;
    Nacy::Texture2D texture;
    float alpha;
    uint64_t initTime;
};


