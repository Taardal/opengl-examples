#pragma once

namespace Demo
{
	enum class EventType
	{
		WindowClose,
		WindowResize
	};

	class Event
	{
	protected:
		EventType type;
		std::string name;
		bool handled;

		Event(const EventType& type, const std::string& name);
		virtual ~Event();

	public:
		const EventType& GetType() const;
		const std::string& GetName() const;
		bool IsHandled() const;
		void SetHandled(bool handled);
		
		virtual const std::string ToString() const;
	};

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

		const std::string ToString() const override;
	};
}