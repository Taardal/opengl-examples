#include "pch.h"
#include "WindowEvent.h"

namespace Demo
{
	WindowCloseEvent::WindowCloseEvent()
		: Event(TO_STRING(WindowCloseEvent), EventType::WindowClose)
	{
	}

	WindowResizeEvent::WindowResizeEvent(int width, int height)
		: Event(TO_STRING(WindowResizeEvent), EventType::WindowResize), width(width), height(height)
	{
	}

	std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << name << "{width=" << width << ", height=" << height << "}";
		return ss.str();
	}
}