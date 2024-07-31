#pragma once
#include <NacyEngine.h>
#include <irrklang/irrKlang.h>
class BeatBap
{
private:
	static Nacy::Application* app;
public:

	static Nacy::Application* GetApplication()
	{
		if (app == nullptr)
		{
			app = new Nacy::Application(
				Nacy::WindowConfig("BeatBap", true, 1280, 720, true, true)
			);
		}
		return app;
	}

	void Init();
	void Run();
	void Stop();
};
