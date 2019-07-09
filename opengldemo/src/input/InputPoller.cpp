#include "pch.h"
#include "InputPoller.h"

namespace Demo
{
	InputPoller::InputPoller(GLFWwindow* glfwWindow)
		: tag(TO_STRING(Input)), glfwWindow(glfwWindow)
	{
		LOG_TRACE(tag, "Created");
	}

	InputPoller::~InputPoller()
	{
		LOG_TRACE(tag, "Destroyed");
	}

	bool InputPoller::IsKeyPressed(int keyCode) const
	{
		int state = glfwGetKey(glfwWindow, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputPoller::IsMouseButtonPressed(int keyCode) const
	{
		int state = glfwGetMouseButton(glfwWindow, keyCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> InputPoller::GetMousePosition() const
	{
		double x;
		double y;
		glfwGetCursorPos(glfwWindow, &x, &y);
		return { (float) x, (float) y };
	}
}