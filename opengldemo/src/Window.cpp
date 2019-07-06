#include "pch.h"
#include "Window.h"

namespace Demo
{
	Window::Window(const std::string& title, int width, int height)
		: windowData({ title, width, height })
	{
		logger = std::make_unique<Logger>(typeid(Window).name());
		logger->Trace("Creating");
		InitGlfw();
		glfwWindow = GetGlfwWindow();
		glfwMakeContextCurrent(glfwWindow);
		glfwSetWindowUserPointer(glfwWindow, &windowData);
		SetGlfwCallbacks();
		logger->Trace("Created");
	}

	Window::~Window()
	{
		logger->Trace("Destroying");
		TerminateGlfw();
		logger->Trace("Destroyed");
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

	void Window::InitGlfw()
	{
		if (!glfwInit())
		{
			logger->Critical("Could not init GLFW");
		}
	}

	void Window::TerminateGlfw()
	{
		glfwTerminate();
		logger->Info("Terminated GLFW");
	}

	GLFWwindow* Window::GetGlfwWindow()
	{
		GLFWwindow* glfwWindow = CreateGlfwWindow();
		if (!glfwWindow)
		{
			logger->Critical("Could not create GLFW window");
			TerminateGlfw();
		}
		return glfwWindow;
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

	void Window::SetGlfwCallbacks()
	{
		glfwSetWindowCloseCallback(glfwWindow, [](GLFWwindow* glfwWindow)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			WindowCloseEvent event;
			windowData->OnEvent(event);
		});
		glfwSetWindowSizeCallback(glfwWindow, [](GLFWwindow* glfwWindow, int width, int height)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			windowData->Width = width;
			windowData->Height = height;
			WindowResizeEvent event(width, height);
			windowData->OnEvent(event);
		});
	}

}