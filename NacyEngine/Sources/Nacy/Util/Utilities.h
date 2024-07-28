#pragma once
#include "Nacy/Core/Core.h"

namespace Utility
{
    NACY_API double GetGLFWTime();
    //get format time
    NACY_API std::string GetTime(const char* format);
    //get nano time include ms
    NACY_API long long GetNowTime();
}

