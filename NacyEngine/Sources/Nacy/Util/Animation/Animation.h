#pragma once

#include "Nacy/Core/Core.h"

namespace Utility {
    enum class Direction {
        FORWARD, BACK
    };
    enum class Easing {
        Linear, EaseInQuad, EaseOutQuad, EaseInOutQuad
    };

    class Animator {
    public:
        NACY_API Animator(double ms, Easing easing, double start, double end);

        NACY_API double GetPoint(double delta);

        NACY_API bool HasFinished();

        NACY_API void ChangeDirection(Direction direction);

        NACY_API Direction GetDirection();

    private:
        double time, ms;
        double start, end;
        double point;
        Easing easing;
        Direction direction;
    };

}
