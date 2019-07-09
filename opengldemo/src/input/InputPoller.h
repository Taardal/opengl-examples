#pragma once

#include "graphics/GraphicsContext.h"

namespace Demo
{
	class InputPoller
	{
	private:
		std::string tag;
		GLFWwindow* glfwWindow;

	public:
		InputPoller(GLFWwindow* glfwWindow);
		~InputPoller();

		bool IsKeyPressed(int keyCode) const;
		bool IsMouseButtonPressed(int keyCode) const;
		std::pair<float, float> GetMousePosition() const;
	};
}
