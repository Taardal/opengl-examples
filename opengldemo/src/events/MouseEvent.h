#pragma once

#include "Event.h"

namespace Demo
{
	class MouseMovedEvent : public Event
	{
	private:
		float x;
		float y;

	public:
		MouseMovedEvent(float x, float y);

		virtual std::string ToString() const override;

		float GetX() const;
		float GetY() const;
	};

	class MouseScrolledEvent : public Event
	{
	private:
		float xOffset;
		float yOffset;

	public:
		MouseScrolledEvent(float xOffset, float yOffset);

		virtual std::string ToString() const override;

		float GetXOffset() const;
		float GetYOffset() const;
	};

	class MouseButtonEvent : public Event
	{
	private:
		int button;

	protected:
		MouseButtonEvent(const std::string& name, EventType type, int button);

		virtual std::string ToString() const override;

	public:
		int GetButton() const;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button);
	};
}