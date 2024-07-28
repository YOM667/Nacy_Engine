#pragma once

#include "Nacy/Core/Core.h"
namespace Nacy
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
		Event& event;

		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event);
		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.Handled = func(static_cast<T&>(event));
				return true;
			}
			return false;
		}
	};

	std::ostream& operator<<(std::ostream& os, const Event& ev);
	

}