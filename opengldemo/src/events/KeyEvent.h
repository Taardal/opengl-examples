#pragma once

#include "Event.h"

namespace Demo
{
	class KeyEvent : public Event
	{
	private:
		int keyCode;

	protected:
		KeyEvent(const std::string& name, EventType type, int keyCode);

	public:
		virtual std::string ToString() const override;
		virtual int GetKeyCode() const;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode);
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
	};

	class KeyRepeatedEvent : public KeyEvent
	{
	public:
		KeyRepeatedEvent(int keyCode);
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keyCode);
	};
}