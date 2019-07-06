#include "pch.h"
#include "Window.h"

namespace Demo
{
	Window::Window(const std::string& title, int width, int height)
		: windowData({ title, width, height }), logger(typeid(Window).name())
	{
		logger.Trace("Creating");
		Init();
		
		glfwSetWindowUserPointer(glfwWindow, &windowData);
		glfwSetWindowCloseCallback(glfwWindow, [](GLFWwindow* window)
		{
			WindowData* windowData = (WindowData*) glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			windowData->OnEvent(event);
		});
		logger.Trace("Created");
	}

	Window::~Window()
	{
		logger.Trace("Destroying");
		Shutdown();
		logger.Trace("Destroyed");
	}

	void Window::SetEventListener(const std::function<void(Event&)>& onEvent)
	{
		windowData.OnEvent = onEvent;
	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}

	void Window::Init()
	{
		if (!glfwInit())
		{
			logger.Critical("Could not init GLFW");
		}
		glfwWindow = CreateGlfwWindow();
		if (!glfwWindow)
		{
			Shutdown();
			logger.Error("Could not create GLFW window");
		}
		glfwMakeContextCurrent(glfwWindow);
	}

	void Window::Shutdown()
	{
		logger.Trace("Shutting down");
		glfwTerminate();
		logger.Info("Terminated GLFW");
		logger.Trace("Shut down");
	}

	GLFWwindow* Window::CreateGlfwWindow()
	{
		GLFWmonitor* fullscreenMonitor = NULL;
		GLFWwindow* sharedWindow = NULL;
		return glfwCreateWindow(
			windowData.Width, 
			windowData.Height, 
			windowData.Title.c_str(), 
			fullscreenMonitor, 
			sharedWindow
		);
	}
}