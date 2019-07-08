#include "pch.h"
#include "Event.h"

namespace Demo
{
	Event::Event(const std::string& name, EventType type)
		: type(type), name(name), handled(false)
	{
	}

	const std::string& Event::GetName() const
	{
		return name;
	}

	EventType Event::GetType() const
	{
		return type;
	}

	bool Event::IsHandled() const
	{
		return handled;
	}

	void Event::SetHandled(bool handled)
	{
		this->handled = handled;
	}

	std::string Event::ToString() const
	{
		std::stringstream ss;
		ss << name << "{}";
		return ss.str();
	}
}