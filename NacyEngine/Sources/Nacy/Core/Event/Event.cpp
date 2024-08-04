#include "pch.h"
#include "Event.h"

namespace Nacy {

    std::ostream &operator<<(std::ostream &os, const Event &ev) {
        return os << ev.GetName();
    }

    EventDispatcher::EventDispatcher(Event &event) : event(event) {}
}