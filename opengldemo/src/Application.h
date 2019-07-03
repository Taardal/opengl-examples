#pragma once

#include "Window.h"

namespace Demo
{
	class Application
	{
	private:
		Window* window;

	public:
		Application();
		~Application();

		void Run();
	};
}

