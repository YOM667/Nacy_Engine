#pragma once

#include "pch.h"

namespace Nacy {

    static uint32_t nextID() {
        static uint32_t nextID;
        nextID++;
        return nextID;
    }

    struct Component {
        uint32_t id;

        static std::string GetStaticType() {
            return "component";
        }

        virtual std::string GetType() {
            return "component";
        }

        Component() : id(nextID()) {}

        Component(uint32_t id) : id(id) {}
    };
}


