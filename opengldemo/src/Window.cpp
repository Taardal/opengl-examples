#include "pch.h"
#include "Window.h"
#include "Log.h"

namespace Demo
{
	Window::Window(std::string title, int width, int height)
		: windowData({ title, width, height })
	{
		LOG_INFO("Creating window");
		Init();
		
		glfwSetWindowUserPointer(glfwWindow, &windowData);
		glfwSetWindowCloseCallback(glfwWindow, [](GLFWwindow* window)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			windowData.ShouldClose = true;
		});
	}

	Window::~Window()
	{
		Shutdown();
		LOG_INFO("Destroyed window");
	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}

	bool Window::ShouldClose()
	{
		return windowData.ShouldClose;
	}

	void Window::Init()
	{
		if (!glfwInit())
		{
			LOG_ERROR("Could not init GLFW");
		}
		glfwWindow = CreateGlfwWindow();
		if (!glfwWindow)
		{
			Shutdown();
			LOG_ERROR("Could not create GLFW window");
		}
		glfwMakeContextCurrent(glfwWindow);
	}

	void Window::Shutdown()
	{
		glfwTerminate();
	}

	GLFWwindow* Window::CreateGlfwWindow()
	{
		GLFWmonitor* fullscreenMonitor = NULL;
		GLFWwindow* sharedWindow = NULL;
		return glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str(), fullscreenMonitor, sharedWindow);
	}
}