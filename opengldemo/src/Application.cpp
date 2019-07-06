#include "pch.h"
#include "Application.h"

namespace Demo
{
	Application::Application()
		: tag(TAG(Application)), running(false)
	{
		LOG_T(tag, "Creating");
		window = new Window("OpenGL Demo", 640, 480);
		window->SetEventListener([this](const Event& event)
		{
			OnEvent(event);
		});
		LOG_T(tag, "Created");
	}

	Application::~Application()
	{
		LOG_T(tag, "Destroying");
		delete window;
		LOG_T(tag, "Destroyed");
	}

	void Application::Run()
	{
		SetRunning(true);
		while (running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
		}
	}

	void Application::OnEvent(const Event& event)
	{
		LOG_I(tag, "Received event [{0}]", event.ToString());
		if (event.GetType() == EventType::WindowClose)
		{
			SetRunning(false);
		}
		if (event.GetType() == EventType::WindowResize)
		{
		}
	}

	void Application::SetRunning(bool running)
	{
		LOG_I(tag, "Running [{0}]", running);
		this->running = running;
	}
}
