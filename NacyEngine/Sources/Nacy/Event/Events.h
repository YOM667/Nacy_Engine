#pragma once
#include <pch.h>
#include "Nacy/Core/Core.h"
namespace Engine
{
	enum class EventCategory
	{
		KEY_PRESSED, KEY_RELEASED, KEY_TYPED,
		MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_SCROLLED, MOUSE_MOVING,
		WINDOW_RESIZE,WINDOW_CLOSE,WINDOW_FOCUS,WINDOW_MOVED
	};
	class NACY_API Event
	{
		friend class EventDispatcher;
	public:
		bool Handled = false;

		virtual EventCategory GetEventType() const = 0;
		virtual const char* GetName() const = 0;
	};
	class NACY_API EventDispatcher
	{
	private:
		Event& m_Event;

		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& ev)
	{
		return os << ev.GetName();
	}
}