#include "pch.h"
#include "Application.h"
#include "Log.h"

namespace Demo
{
	Application::Application()
	{
		Log::Init();
		LOG_INFO("Creating application");
		window = new Window("OpenGL Demo", 640, 480);
	}

	Application::~Application()
	{
		delete window;
		LOG_INFO("Destroyed application");
	}

	void Application::Run()
	{
		LOG_INFO("Running application");
		while (!window->ShouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
		}
	}
}
