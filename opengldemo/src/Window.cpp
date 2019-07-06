#include "pch.h"
#include "Window.h"

namespace Demo
{
	static bool glfwInitialized = false;

	Window::Window(const std::string& title, int width, int height)
		: tag(TO_STRING(Window)), windowData({ title, width, height })
	{
		InitGlfw();
		glfwWindow = GetGlfwWindow();
		glfwMakeContextCurrent(glfwWindow);
		glfwSetWindowUserPointer(glfwWindow, &windowData);
		SetGlfwCallbacks();
	}

	Window::~Window()
	{
		TerminateGlfw();
	}

	void Window::SetEventCallback(const std::function<void(Event&)>& onEvent)
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
		if (!glfwInitialized)
		{
			if (!glfwInit())
			{
				LOG_C(tag, "Could not init GLFW");
			}
		}
	}

	void Window::TerminateGlfw()
	{
		glfwTerminate();
		LOG_I(tag, "Terminated GLFW");
	}

	GLFWwindow* Window::GetGlfwWindow()
	{
		GLFWwindow* glfwWindow = CreateGlfwWindow();
		if (!glfwWindow)
		{
			LOG_C(tag, "Could not create GLFW window");
			TerminateGlfw();
		}
		return glfwWindow;
	}

	GLFWwindow* Window::CreateGlfwWindow()
	{
		GLFWmonitor* fullscreenMonitor = nullptr;
		GLFWwindow* sharedWindow = nullptr;
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
		SetGlfwWindowCallbacks();
		SetGlfwKeyCallbacks();
		SetGlfwMouseCallbacks();
	}

	void Window::SetGlfwWindowCallbacks()
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

	void Window::SetGlfwKeyCallbacks()
	{
		glfwSetKeyCallback(glfwWindow, [](GLFWwindow* glfwWindow, int key, int scancode, int action, int mods)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key);
				windowData->OnEvent(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				windowData->OnEvent(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyRepeatedEvent event(key);
				windowData->OnEvent(event);
				break;
			}
			}
		});
		glfwSetCharCallback(glfwWindow, [](GLFWwindow* glfwWindow, unsigned int keycode)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			KeyTypedEvent event(keycode);
			windowData->OnEvent(event);
		});
	}

	void Window::SetGlfwMouseCallbacks()
	{
		glfwSetMouseButtonCallback(glfwWindow, [](GLFWwindow* glfwWindow, int button, int action, int mods)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				windowData->OnEvent(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				windowData->OnEvent(event);
				break;
			}
			}
		});
	}

}