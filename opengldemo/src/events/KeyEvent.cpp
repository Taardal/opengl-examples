#include "pch.h"
#include "KeyEvent.h"

namespace Demo
{
	KeyEvent::KeyEvent(const std::string& name, EventType type, int keyCode)
		: Event(name, type), keyCode(keyCode)
	{
	}

	int KeyEvent::GetKeyCode() const
	{
		return keyCode;
	}

	std::string KeyEvent::ToString() const
	{
		std::stringstream ss;
		ss << name << "{keyCode=" << keyCode << "}";
		return ss.str();
	}

	KeyPressedEvent::KeyPressedEvent(int keyCode)
		: KeyEvent(TO_STRING(KeyPressedEvent), EventType::KeyPressed, keyCode)
	{
	}

	KeyReleasedEvent::KeyReleasedEvent(int keyCode)
		: KeyEvent(TO_STRING(KeyReleasedEvent), EventType::KeyReleased, keyCode)
	{
	}

	KeyRepeatedEvent::KeyRepeatedEvent(int keyCode)
		: KeyEvent(TO_STRING(KeyRepeatedEvent), EventType::KeyRepeated, keyCode)
	{
	}

	KeyTypedEvent::KeyTypedEvent(int keyCode)
		: KeyEvent(TO_STRING(KeyTypedEvent), EventType::KeyTyped, keyCode)
	{
	}
}