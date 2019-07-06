#include "pch.h"
#include "MouseEvent.h"

namespace Demo
{
	MouseMovedEvent::MouseMovedEvent(float x, float y)
		: Event(TO_STRING(MouseMovedEvent), EventType::MouseMoved), x(x), y(y)
	{
	}

	float MouseMovedEvent::GetX() const 
	{ 
		return x; 
	}	
	
	float MouseMovedEvent::GetY() const 
	{ 
		return y;
	}

	std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss << name << "{x=" << x << ", y=" << y << "}";
		return ss.str();
	}

	MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset)
		: Event(TO_STRING(MouseScrolledEvent), EventType::MouseScrolled), xOffset(xOffset), yOffset(yOffset)
	{
	}

	float MouseScrolledEvent::GetXOffset() const
	{
		return xOffset;
	}

	float MouseScrolledEvent::GetYOffset() const
	{
		return yOffset;
	}

	std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss << name << "{xOffset=" << xOffset << ", yOffset=" << yOffset << "}";
		return ss.str();
	}

	MouseButtonEvent::MouseButtonEvent(const std::string& name, EventType type, int button)
		: Event(name, type), button(button)
	{
	}

	std::string MouseButtonEvent::ToString() const
	{
		std::stringstream ss;
		ss << name << "{button=" << button << "}";
		return ss.str();
	}

	int MouseButtonEvent::GetButton() const
	{
		return button;
	}
	
	MouseButtonPressedEvent::MouseButtonPressedEvent(int button)
		: MouseButtonEvent(TO_STRING(MouseButtonPressedEvent), EventType::MouseButtonPressed, button)
	{
	}

	MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button)
		: MouseButtonEvent(TO_STRING(MouseButtonReleasedEvent), EventType::MouseButtonReleased, button)
	{
	}
}
