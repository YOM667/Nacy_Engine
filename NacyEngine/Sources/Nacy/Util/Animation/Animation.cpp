#include "pch.h"
#include "Animation.h"

namespace Utility {
    double linear(double startTime, double startPoint, double distance, double time) {
        return distance * startTime / time + startPoint;
    }

    double easeInQuad(double startTime, double startPoint, double distance, double time) {
        return distance * (startTime /= time) * startTime + startPoint;
    }

    double easeOutQuad(double startTime, double startPoint, double distance, double time) {
        return -distance * (startTime /= time) * (startTime - 2) + startPoint;
    }

    Animator::Animator(double ms, Easing easing, double start, double end) : ms(ms), easing(easing), start(start),
                                                                             end(end), time(0),
                                                                             direction(Direction::FORWARD) {
        this->point = start;
    }
    double Animator::GetPoint(double delta) {
        time += (delta);
        switch (this->easing) {
            case Easing::Linear:
                this->point = linear(time, point, end - point, ms);
                break;
            case Easing::EaseInQuad:
                this->point = easeInQuad(time, point, end - point, ms);
                break;
            case Easing::EaseOutQuad:
                this->point = easeOutQuad(time, point, end - point, ms);
                break;
            case Easing::EaseInOutQuad:
                break;
        }
        return this->point;

    }

    bool Animator::HasFinished() {
        if(this->direction == Direction::BACK){
            return this->point <= this->end;
        }else {
            return this->point >= this->end;
        }
    }

    void Animator::ChangeDirection(Direction direction) {
        double cache;
        cache = end;
        end = start;
        start = cache;

        this->time = 0;
        this->point = start;
        this->direction = direction;
    }

    Direction Animator::GetDirection() {
        return this->direction;
    }
}
