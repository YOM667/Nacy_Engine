#pragma once
#include <NacyEngine.h>

#define SECOND(time) time * 1000

using namespace Utility;
namespace Util {
	void EaseAlpha(Utility::Animator* anim, float* alpha) {
        if (anim->GetDirection() != Direction::BACK) {
            if (*alpha < 255.0f) {
                *alpha = anim->GetPoint();
            }
            else {
                anim->ChangeDirection(Direction::BACK);
            }
        }
        else if (anim->GetDirection() != Direction::FORWARD) {
            if (*alpha > 0.0f) {
                *alpha = anim->GetPoint();
            }
            else {
                anim->ChangeDirection(Direction::FORWARD);
            }
        }
	}
    template<typename T>
    T GetRangeRandom(T min, T max) {
        return (rand() % (max - min + 1)) + min;
    }
}