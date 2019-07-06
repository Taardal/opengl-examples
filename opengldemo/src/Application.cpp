#include "pch.h"
#include "Application.h"

namespace Demo
{
	Application::Application()
		: tag(TO_STRING(Application)), running(false)
	{
		window = new Window("OpenGL Demo", 640, 480);
		window->SetEventCallback(BIND_FN(Application::OnEvent));
	}

	Application::~Application()
	{
		delete window;
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
		LOG_I(tag, "Received event: {0}", event.ToString());
		if (event.GetType() == EventType::WindowClose)
		{
			SetRunning(false);
		}
	}

	void Application::SetRunning(bool running)
	{
		LOG_I(tag, "Running: {0}", running);
		this->running = running;
	}
}
