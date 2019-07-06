#include "pch.h"
#include "Application.h"
#include "Event.h"

namespace Demo
{
	Application::Application()
		: window("OpenGL Demo", 640, 480), logger(typeid(Application).name()), running(false)
	{
		logger.Trace("Creating");
		window.SetEventListener([this](const Event& event)
		{
			OnEvent(event);
		});
		logger.Trace("Created");
	}

	Application::~Application()
	{
		logger.Trace("Destroyed");
	}

	void Application::Run()
	{
		SetRunning(true);
		while (running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			window.OnUpdate();
		}
	}

	void Application::OnEvent(const Event& event)
	{
		if (event.GetType() == EventType::WindowClose)
		{
			logger.Info("Received window close event");
			SetRunning(false);
		}
	}

	void Application::SetRunning(bool running)
	{
		logger.Info("Running [{0}]", running);
		this->running = running;
	}
}
