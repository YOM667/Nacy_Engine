#pragma once

#include <string>
#include <unordered_map>
#include <irrklang/irrKlang.h>

struct Sound {
    std::string file;
    bool round;

    Sound() {};

    Sound(std::string file, bool round = false) : file(file), round(round) {};
};

class SoundEngine {
private:
    SoundEngine();

    ~SoundEngine();

    SoundEngine(const SoundEngine &engine) = delete;

public:
    static SoundEngine *GetInstance();

    void LoadSound(const std::string& name, const Sound &sound);

    void StopSounds();

    void NPlaySound(const std::string& name);

private:
    static SoundEngine *instance;
    std::unordered_map<std::string, Sound> sounds;
    irrklang::ISoundEngine *soundPlayer;

};