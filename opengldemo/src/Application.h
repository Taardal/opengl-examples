#pragma once

#include "Log.h"
#include "Window.h"

namespace Demo
{
	class Application
	{
	private:
		Window* window;
		std::string tag;
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

