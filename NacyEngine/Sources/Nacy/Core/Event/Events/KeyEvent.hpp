#pragma once

#include "pch.h"

#include "Nacy/Core/Core.h"
#include "Nacy/Core/Event/Event.h"

namespace Nacy {
    class NACY_API KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

    protected:
        int m_KeyCode;

        KeyEvent(int keycode) : m_KeyCode(keycode) {}
    };


    class NACY_API KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        EventCategory GetEventType() const override {
            return EventCategory::KEY_PRESSED;
        }

        const char *GetName() const override {
            return "KeyPressedEvent";
        }

        static EventCategory GetStaticType() { return EventCategory::KEY_PRESSED; }

    private:
        int m_RepeatCount;
    };


    class NACY_API KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

        EventCategory GetEventType() const override {
            return EventCategory::KEY_RELEASED;
        }

        const char *GetName() const override {
            return "KeyReleasedEvent";
        }

        static EventCategory GetStaticType() { return EventCategory::KEY_RELEASED; }
    };

    class NACY_API KeyTypedEvent : public KeyEvent {
    public:
        KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

        EventCategory GetEventType() const override {
            return EventCategory::KEY_TYPED;
        }

        const char *GetName() const override {
            return "KeyTypedEvent";
        }

        static EventCategory GetStaticType() { return EventCategory::KEY_TYPED; }
    };
}