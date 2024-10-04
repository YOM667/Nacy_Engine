#include "pch.h"
#include "Animation.h"

namespace Utility {

    template<typename T>
    inline T min(T a, T b) {
        return a > b ? b : a;
    }
    template<typename T>
    inline T max(T a, T b) {
        return a < b ? b : a;
    }

    Animator::Animator(int ms, Easing easing, double end)
        : duration(ms), easing(easing), end(end), direction(Direction::FORWARD), correctOutput(false) {
        if (this->easing == Easing::EaseOutSine) {
            correctOutput = true;
        }
    }

    Animator::Animator(int ms, Easing easing, double end, Direction direction)
        : duration(ms), easing(easing), end(end), direction(direction), correctOutput(false) {
        if (this->easing == Easing::EaseOutSine) {
            correctOutput = true;
        }
    }


    double Animator::GetPoint() {
        if (this->direction == Direction::FORWARD) {
            if (timer.HasTimeElapsed(this->duration)) {
                return end;
            }

            return GetEquation(timer.GetTime() / (double)duration) * end;
        }
        else {
            if (timer.HasTimeElapsed(this->duration)) {
                return 0.0;
            }

            if (correctOutput) {
                double revTime = min(duration, max(0LL, duration - timer.GetTime()));
                return GetEquation(revTime / (double)duration) * end;
            }

            return (1 - GetEquation(timer.GetTime() / (double)duration)) * end;
        }
    }

    bool Animator::HasFinished(Direction direction) {
        return timer.HasTimeElapsed(this->duration) && this->direction == direction;

    }

    void Animator::ChangeDirection(Direction direction) {
        if (this->direction != direction) {
            this->direction = direction;
            timer.SetTime(GetMillsTime() - (duration - min(duration, timer.GetTime())));
        }
    }

    Direction Animator::GetDirection() {
        return this->direction;
    }
    double Animator::GetEquation(double x)
    {
        return GetEasingFunc(this->easing,x);
    }
    double GetEasingFunc(Easing easing,double x)
    {
        switch (easing)
        {
        case Easing::Decelerate:
            return 1 - ((x - 1) * (x - 1));
        case Easing::EaseInOutQuad:
            return x < 0.5 ? 2 * std::pow(x, 2) : 1 - std::pow(-2 * x + 2, 2) / 2;
        case Easing::EaseOutSine:
            return sin(x * (PI / 2));
        case Easing::Smooth:
            return -2 * std::pow(x, 3) + (3 * std::pow(x, 2));
        default:
            break;
        }
    }
}
