#pragma once

#include "Window.h"
#include "Logger.h"

namespace Demo
{
	class Application
	{
	private:
		Window window;
		Logger logger;
		bool running;

	public:
		Application();
		~Application();

		void Run();
		void OnEvent(const Event& event);

	private:
		void SetRunning(bool running);
	};
}

