#pragma once

#include <NacyEngine.h>
#include <SoundEngine/SoundEngine.h>
#include <vector>
#include <Game/Loader/SheetManager.h>

class SelectedScene : public Nacy::Scene {
public:
    SelectedScene() : Nacy::Scene(4), scale(100.0f), isScale(false), current(-1) {
        this->animator = new Utility::Animator(0.5f, Utility::Easing::Linear, 100.0f, 107.0f);
        this->animator->ChangeDirection(Utility::Direction::BACK);
    }

    void Init() override {

        this->Clear();
        auto sheet1 = new Nacy::GameObject("Sheet1");
        auto sheetTransform = sheet1->GetComponent<Nacy::TransformComponent>();
        auto sheetTexture = Nacy::ResourceManager::GetTexture2D("logo");
        sheetTransform->position.x = -20.0f;
        sheetTransform->position.y = this->screenHeight / 2.0f - 33.0f;
        sheetTransform->size.x = 400.0f;
        sheetTransform->size.y = 66.6f;
        sheetTransform->scale = scale / 100.0f;
        sheet1->AddComponent(
                new Nacy::SpriteComponent(sheetTexture, Nacy::RGBA(255.0f), Nacy::SpriteType::ROUND, 10.0f));
        this->AddGameObject("Sheet1", sheet1);

    }

    void DrawBackground() override {
        auto texture = Nacy::ResourceManager::GetTexture2D("music_background");
        if (current == 0) {
            this->graphic->sprite->DrawSprite(texture, Nacy::Vector2(0, 0),Nacy::Vector2(this->screenWidth, this->screenHeight), Nacy::RGBA(255.0f));
            this->graphic->shape->DrawRect(Nacy::Vector2(0, 0), Nacy::Vector2(this->screenWidth, this->screenHeight),
                                           Nacy::RGBA(0.0f, 0.0f, 0.0f, 200.0f), 1.0f);

            if (this->isHovered(Nacy::Vector2(screenWidth - 150, screenHeight - 70), Nacy::Vector2(140, 60))) {
                this->graphic->shape->DrawRoundedRectOutline(Nacy::Vector2(screenWidth - 150, screenHeight - 70), Nacy::Vector2(140, 60), 5, 0.5f,
                                                             Nacy::RGBA(255.0f,255.0f,255.0f,255.0f),
                                                             Nacy::RGBA(0.0f, 0.0f, 0.0f, 80.0f), 1.0f);

            }else{
                this->graphic->shape->DrawRoundedRect(Nacy::Vector2(screenWidth - 150, screenHeight - 70), Nacy::Vector2(140, 60), 5,
                                                      Nacy::RGBA(0.0f, 0.0f, 0.0f, 80.0f), 1.0f);
            }

            this->graphic->text->GetFont("comici_20").RenderCenterdText("Start", Nacy::Vector2(screenWidth - 80, screenHeight - 48),
                                                                        1.0f, Nacy::RGBA(255.0f));
        }
    }

    void Update(double delta) override {
        this->mouseX = Nacy::InputManager::mouseX;
        this->mouseY = Nacy::InputManager::mouseY;
        auto transform = this->GetGameObject("Sheet1")->GetComponent<Nacy::TransformComponent>();

        this->isScale = this->isHovered(transform);


        if (isScale) {

            if (this->animator->GetDirection() != Utility::Direction::FORWARD) {
                this->animator->ChangeDirection(Utility::Direction::FORWARD);
            }
            this->scale = this->animator->GetPoint(delta);
            if (playHover) {
                SoundEngine::GetInstance()->NPlaySound("hover");
                this->playHover = false;
            }

        } else {
            if (this->animator->GetDirection() != Utility::Direction::BACK) {
                this->animator->ChangeDirection(Utility::Direction::BACK);
            }
            this->scale = this->animator->GetPoint(delta);
            this->playHover = true;
        }
        transform->scale = this->scale / 100.0f;
    }

    void OnMouseButton(int button) override {
        auto sheetTransform = this->GetGameObject("Sheet1")->GetComponent<Nacy::TransformComponent>();
        if (button == Nacy::LEFT_BUTTON) {
            if (this->isHovered(sheetTransform)) {
                this->current = 0;
            }
        }
    }

private:
    int current;
    bool playHover = false;
    bool isScale;
    float scale;
    //std::vector<Sheet> sheet;
    Utility::Animator *animator;
};

