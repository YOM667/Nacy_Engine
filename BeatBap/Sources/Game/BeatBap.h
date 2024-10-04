#pragma once

#include <NacyEngine.h>
#include <irrklang/irrKlang.h>

class BeatBap {
private:
    static Nacy::Application *app;
public:

    static Nacy::Application *GetApplication() {
        if (app == nullptr) {
            app = new Nacy::Application(Nacy::WindowConfig("BeatBap", true, 900, 600, true, false));
        }
        return app;
    }

    static void Init();

    static void Run();

    static void Stop();
};
