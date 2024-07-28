#pragma once
#include "pch.h"

#include "Nacy/Core/Event/Event.h"
#include "Nacy/Core/Core.h"
namespace Nacy {
	class NACY_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EventCategory GetEventType() const override
		{
			return EventCategory::MOUSE_MOVING;
		}
		const char* GetName() const override
		{
			return "MouseMovedEvent";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::MOUSE_MOVING;
		}
	private:
		float m_MouseX, m_MouseY;
	};


	class NACY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		EventCategory GetEventType() const override
		{
			return EventCategory::MOUSE_SCROLLED;
		}
		const char* GetName() const override
		{
			return "MouseScrolledEvent";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::MOUSE_SCROLLED;
		}
	private:
		float m_XOffset, m_YOffset;
	};


	class NACY_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EventCategory GetEventType() const override
		{
			return EventCategory::MOUSE_BUTTON_PRESSED;
		}
		const char* GetName() const override
		{
			return "MouseButtonEvent";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::MOUSE_BUTTON_PRESSED;
		}
	protected:
		int m_Button;

		MouseButtonEvent(int button)
			:m_Button(button) {}


	};

	class NACY_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}
		EventCategory GetEventType() const override
		{
			return EventCategory::MOUSE_BUTTON_PRESSED;
		}
		const char* GetName() const override
		{
			return "MouseButtonPressed";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::MOUSE_BUTTON_PRESSED;
		}
	};

	class NACY_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}
		EventCategory GetEventType() const override
		{
			return EventCategory::MOUSE_BUTTON_RELEASED;
		}
		const char* GetName() const override
		{
			return "MouseButtonReleased";
		}
		static EventCategory GetStaticType() 
		{ 
			return EventCategory::MOUSE_BUTTON_RELEASED;
		}
	};

}