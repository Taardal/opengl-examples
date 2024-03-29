#pragma once

#include <GLFW/glfw3.h>

namespace Demo
{
	class InputPoller
	{
	public:
		InputPoller();
		~InputPoller();

		bool IsKeyPressed(int keyCode) const;
		bool IsMouseButtonPressed(int keyCode) const;
		std::pair<float, float> GetMousePosition() const;
	};
}
