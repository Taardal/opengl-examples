#pragma once

#include "Event.h"

namespace Demo
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent();
	};

	class WindowResizeEvent : public Event
	{
	private:
		int width;
		int height;

	public:
		WindowResizeEvent(int width, int height);

		virtual std::string ToString() const override;
	};
}