#pragma once
#include "pch.h"
#include "Nacy/Core/Event/Event.h"

namespace Nacy {
	class NACY_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height) : width(width), height(height) {}

		inline int GetWidth() const { return width; }
		inline int GetHeight() const { return height; }

		EventCategory GetEventType() const override
		{
			return EventCategory::WINDOW_RESIZE;
		}
		const char* GetName() const override
		{
			return "WindowResizeEvent";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::WINDOW_RESIZE;
		}
	private:
		float width, height;
	};


	class NACY_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		EventCategory GetEventType() const override
		{
			return EventCategory::WINDOW_CLOSE;
		}
		const char* GetName() const override
		{
			return "WindowCloseEvent";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::WINDOW_CLOSE;
		}

	};
	class NACY_API WindowFocusEvent: public Event
	{
	public:
		WindowFocusEvent() {}
		EventCategory GetEventType() const override
		{
			return EventCategory::WINDOW_FOCUS;
		}
		const char* GetName() const override
		{
			return "WindowFocusEvent";
		}
		static EventCategory GetStaticType()
		{
			return EventCategory::WINDOW_FOCUS;
		}

	};

}