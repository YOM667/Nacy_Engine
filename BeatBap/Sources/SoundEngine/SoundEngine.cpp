#include "SoundEngine.h"

SoundEngine* SoundEngine::instance = nullptr;

SoundEngine::SoundEngine()
{
	this->soundPlayer = irrklang::createIrrKlangDevice();
}

SoundEngine::~SoundEngine()
{
	this->soundPlayer->drop();
	this->sounds.clear();
}

SoundEngine* SoundEngine::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SoundEngine();
	}
	return instance;
}

void SoundEngine::LoadSound(std::string name, Sound sound)
{
	this->sounds[name] = sound;
}

void SoundEngine::StopSounds()
{
	this->soundPlayer->stopAllSounds();
}

void SoundEngine::NPlaySound(std::string name)
{
	auto& sound = this->sounds[name];

	this->soundPlayer->play2D(sound.file.c_str(), sound.round);
}
