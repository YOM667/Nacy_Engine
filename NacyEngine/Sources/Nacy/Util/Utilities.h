#pragma once

#include "Nacy/Core/Core.h"

#define SECOND(x) (x * 1000000000)

namespace Utility {
    NACY_API double GetGLFWTime();
    //get format time
    NACY_API std::string GetTime(const char* format);
    //get nano time include ms
    NACY_API long long GetMillsTime();
    NACY_API long long GetNanoTime();
    class Timer {

    private:
        uint64_t lastMS;
    public:
        Timer() : lastMS(GetMillsTime()) {}

        NACY_API void Reset();

        NACY_API bool HasTimeElapsed(long long time, long long reset);
        NACY_API bool HasTimeElapsed(long long time);

        NACY_API bool HasTimeElapsed(double time);
        NACY_API bool HasTimeElapsed(int time);
        NACY_API long long GetTime();

        NACY_API void SetTime(long long time);

    };


}

