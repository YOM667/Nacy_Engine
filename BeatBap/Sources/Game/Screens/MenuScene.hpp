#pragma once

#include <NacyEngine.h>
#include "SoundEngine/SoundEngine.h"
#include "Game/Renderer/BGRenderer.hpp"
#include "SelectedScene.hpp"
#include "Game/BeatBap.h"

class MenuScene : public Nacy::Scene {
public:
    bool enter = true;

    MenuScene() : Scene(2), pressed(false), alpha(0.0) {
        this->background = std::make_unique<BGRenderer>();
        this->animator = std::make_unique<Utility::Animator>(4.0, Utility::Easing::EaseInQuad, 0.0, 255.0);

    }

    void DrawBackground() override {
        this->background->Draw(Nacy::Vector2(0, 0), Nacy::Vector2(this->screenWidth, this->screenHeight), this->alpha);
        this->graphic->text->GetFont("ditty_big").RenderCenterdText("Beat Bap",
                                                                    Nacy::Vector2(screenWidth / 2.0f,screenHeight / 4.0f),
                                                                    1.0f,
                                                                    Nacy::RGBA(255.0f,255.0f,255.0f,this->alpha));
        this->graphic->text->GetFont("ditty").RenderCenterdText("---[ Press any key to start the game ]---",
                                                                    Nacy::Vector2(screenWidth / 2.0f, screenHeight - 100),
                                                                    1.0f,
                                                                    Nacy::RGBA(255.0f, 255.0f, 255.0f,this->alpha));
    }

    void Enter() {
        if (enter) {
            SoundEngine::GetInstance()->NPlaySound("music");
            enter = false;
        }
    }

    void Init() override {
        this->Clear();
        this->Enter();
        this->background->SetProjection();
        Nacy::KeyBinding enterKeyBinding([this](auto action) {
            if (action == Nacy::KeyActionType::KEY_PRESSED){
                this->pressed = true;
            }
        });
        Nacy::InputManager::RegisterKeyBinding("enter", enterKeyBinding);
    }

    void Update(double delta) override {
        if (alpha <= 255.0) {
            alpha = this->animator->GetPoint(delta);
        }
        if (pressed) {
            if (this->animator->GetDirection() != Utility::Direction::BACK) {
                this->animator->ChangeDirection(Utility::Direction::BACK);
            }
            if (alpha >= 0) {
                alpha = this->animator->GetPoint(delta);
            }
            if (alpha <= 0) {
                SoundEngine::GetInstance()->StopSounds();
                Nacy::SceneManager::GetInstance()->DisplayScene(new SelectedScene());
            }
        }
    }

private:
    std::unique_ptr<Utility::Animator> animator;
    std::unique_ptr<BGRenderer> background;
    bool pressed;
    float alpha;

};


