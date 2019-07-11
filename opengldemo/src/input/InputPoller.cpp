#include "pch.h"
#include "InputPoller.h"

namespace Demo
{
	std::string InputPoller::tag = TO_STRING(InputPoller);

	InputPoller::InputPoller()
	{
		LOG_TRACE(tag, "Created");
	}

	InputPoller::~InputPoller()
	{
		LOG_TRACE(tag, "Destroyed");
	}

	bool InputPoller::IsKeyPressed(int keyCode) const
	{
		int state = glfwGetKey(glfwGetCurrentContext(), keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputPoller::IsMouseButtonPressed(int keyCode) const
	{
		int state = glfwGetMouseButton(glfwGetCurrentContext(), keyCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> InputPoller::GetMousePosition() const
	{
		double x;
		double y;
		glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);
		return { (float) x, (float) y };
	}
}