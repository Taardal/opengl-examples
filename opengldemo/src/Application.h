#pragma once

#include "Window.h"
#include "Logger.h"

namespace Demo
{
	class Application
	{
	private:
		std::unique_ptr<Logger> logger;
		std::unique_ptr<Window> window;
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

