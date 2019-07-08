#pragma once

#include "Core.h"

namespace Demo
{
	enum class EventType
	{
		WindowClose,
		WindowResize,
		KeyPressed,
		KeyReleased,
		KeyRepeated,
		KeyTyped,
		MouseMoved,
		MouseScrolled,
		MouseButtonPressed,
		MouseButtonReleased
	};

	class Event
	{
	protected:
		std::string name;
		EventType type;
		bool handled;

	protected:
		Event(const std::string& name, EventType type);
		virtual ~Event() = default;

	public:
		virtual std::string ToString() const;

		const std::string& GetName() const;
		EventType GetType() const;
		bool IsHandled() const;
		void SetHandled(bool handled);
	};
}