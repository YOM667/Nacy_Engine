#pragma once

#include "Nacy/Core/Core.h"
#include "Nacy/Util/Utilities.h"
namespace Utility {
    enum class Direction {
        FORWARD, BACK
    };
    enum class Easing {
        Decelerate, EaseBackIn, EaseInOutQuad, EaseOutSine, Smooth
    };
    double GetEasingFunc(Easing easing, double x);
    class Animator {
    public:
        NACY_API Animator(int ms, Easing easing, double end);

        NACY_API Animator(int ms, Easing easing, double end, Direction direction);

        NACY_API double GetPoint();

        NACY_API bool HasFinished(Direction direction);

        NACY_API void ChangeDirection(Direction direction);

        NACY_API Direction GetDirection();

        NACY_API double GetEquation(double x);

    private:
        bool correctOutput;
        Timer timer;
        long long duration;
        double end;
        Easing easing;
        Direction direction;
    };

}
