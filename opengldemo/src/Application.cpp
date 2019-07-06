#include "pch.h"
#include "Application.h"
#include "Event.h"

namespace Demo
{
	Application::Application()
	{
		logger = std::make_unique<Logger>(typeid(Application).name());
		logger->Trace("Creating");
		window = std::make_unique<Window>("OpenGL Demo", 640, 480);
		window->SetEventListener([this](const Event& event)
		{
			OnEvent(event);
		});
		logger->Trace("Created");
	}

	Application::~Application()
	{
		logger->Trace("Destroyed");
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
		logger->Info("Received event [{0}]", event.ToString());
		//logger->Info("Received event [{0}]", event.GetName());
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
		logger->Info("Running [{0}]", running);
		this->running = running;
	}
}
