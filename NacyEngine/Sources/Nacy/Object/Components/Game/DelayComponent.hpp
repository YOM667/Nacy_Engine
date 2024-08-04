#pragma once

#include <iostream>
#include "Nacy/Object/Components/Component.hpp"

namespace Nacy {
    struct DelayComponent : public Component {
        uint64_t delayTime;

        explicit DelayComponent(uint64_t delayTime) : delayTime(delayTime) {}

        static std::string GetStaticType() {
            return "delay";
        }

        std::string GetType() override {
            return "delay";
        }
    };

}