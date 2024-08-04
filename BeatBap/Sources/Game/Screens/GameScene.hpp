#pragma once

#include <NacyEngine.h>
#include "Objects/Objects.hpp"
#include "../Loader/SheetManager.h"
#include "../../SoundEngine/SoundEngine.h"

class GameScene : public Nacy::Scene {
public:
    GameScene() : Scene(7), running(false) {
        this->loader = new SheetLoader();
        this->sheet = loader->Read();
    }

    void Init() override {
        for (int barLineIndex = 0; barLineIndex < 5; barLineIndex++) {
            auto name = "BarLine" + std::to_string(barLineIndex);
            auto line = new BarLineObject(barLineIndex);
            this->AddGameObject(name, line);
        }
        for (int checkLineIndex = 0; checkLineIndex < 4; checkLineIndex++) {
            auto name = "CheckLine" + std::to_string(checkLineIndex);
            auto line = new CheckLineNode(checkLineIndex);
            this->AddGameObject(name, line);
        }
        int index = 0;
        for (auto &beat: sheet.beats) {
            if (beat.channel >= 5) {
                continue;
            }
            BeatObject *beatObject = new BeatObject(beat.channel - 1, beat.speed,
                                                    sheet.time + beat.appearance * 1000000000.0);
            auto name = "Beat" + std::to_string(index);
            this->AddGameObject(name, beatObject);
            index++;
        }
        this->texture = Nacy::ResourceManager::GetTexture2D("music_background");
        SoundEngine::GetInstance()->NPlaySound("Engine x Start");
    }

    void DrawBackground() override {
        this->graphic->sprite->DrawSprite(texture, Nacy::Vector2(0, 0), Nacy::Vector2(this->screenWidth, this->screenHeight));
        this->graphic->shape->DrawRect(Nacy::Vector2(0, 0), Nacy::Vector2(this->screenWidth, this->screenHeight),
                                       Nacy::RGBA(0.0f, 0.0f, 0.0f, 150.0f), 1.0f);
    }

private:
    Sheet sheet;
    SheetLoader *loader;
    bool running;
    uint32_t score{0};
    Nacy::Texture2D texture;
};
