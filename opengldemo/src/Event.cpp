#include "pch.h"
#include "Event.h"

namespace Demo
{
	Event::Event(EventType type, const std::string& name)
		: type(type), name(name), handled(false)
	{
	}

	const EventType& Event::GetType() const
	{
		return type;
	}

	const std::string& Event::GetName() const
	{
		return name;
	}

	bool Event::IsHandled() const
	{
		return handled;
	}

	void Event::SetHandled(bool handled)
	{
		this->handled = handled;
	}

	const std::string Event::ToString() const
	{
		return GetName();
	}

	WindowCloseEvent::WindowCloseEvent()
		: Event(EventType::WindowClose, TO_STRING(WindowCloseEvent))
	{
	}

	WindowResizeEvent::WindowResizeEvent(int width, int height)
		: Event(EventType::WindowResize, TO_STRING(WindowResizeEvent)), width(width), height(height)
	{
	}

	const std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << GetName() << ": " << width << ", " << height;
		return ss.str();
	}

}