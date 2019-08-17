#include "pch.h"
#include "Window.h"
#include "events/WindowEvent.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

namespace Demo
{
	bool Window::glfwInitialized = false;

	Window::Window(const std::string& title, int width, int height)
		: windowData({ title, width, height })
	{
		InitGlfw();
		glfwWindow = CreateGlfwWindow();
		graphicsContext = new GraphicsContext(glfwWindow);
		glfwSetWindowUserPointer(glfwWindow, &windowData);
		SetGlfwCallbacks();
		SetVSync(true);
		LOG_TRACE(TAG, "Created");
	}

	Window::~Window()
	{
		delete graphicsContext;
		TerminateGlfw();
		LOG_TRACE(TAG, "Destroyed");
	}

	void Window::OnUpdate()
	{
		graphicsContext->SwapBuffers();
		glfwPollEvents();
	}

	void Window::SetEventListener(const std::function<void(const Event&)>& onEvent)
	{
		windowData.OnEvent = onEvent;
	}

	float Window::GetWidth() const
	{
		return (float) windowData.Width;
	}

	float Window::GetHeight() const
	{
		return (float) windowData.Height;
	}

	bool Window::IsVync() const
	{
		return windowData.VSync;
	}

	void Window::SetVSync(bool vSync)
	{
		int interval = vSync ? 1 : 0;
		glfwSwapInterval(interval);
		windowData.VSync = vSync;
	}

	void Window::OnGlfwError(int error, const char* description)
	{
		LOG_ERROR(TAG_1(Window), "GLFW error ({0}): {1}", error, description);
	}

	void Window::InitGlfw()
	{
		if (!glfwInitialized)
		{
			if (glfwInit() == GLFW_TRUE)
			{
				glfwSetErrorCallback(OnGlfwError);
				glfwInitialized = true;
				LOG_INFO(TAG, "GLFW initialized");
			}
			else
			{
				LOG_CRITICAL(TAG, "Could not init GLFW");
			}
		}
	} 

	GLFWwindow* Window::CreateGlfwWindow()
	{
		GLFWmonitor* fullscreenMonitor = nullptr;
		GLFWwindow* sharedWindow = nullptr;
		GLFWwindow* glfwWindow = glfwCreateWindow(
			windowData.Width,
			windowData.Height,
			windowData.Title.c_str(),
			fullscreenMonitor,
			sharedWindow
		);
		if (!glfwWindow)
		{
			LOG_CRITICAL(TAG, "Could not create GLFW window");
		}
		return glfwWindow;
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
		glfwSetCursorPosCallback(glfwWindow, [](GLFWwindow* glfwWindow, double xpos, double ypos)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			MouseMovedEvent event((float) xpos, (float) ypos);
			windowData->OnEvent(event);
		});
	}

	void Window::TerminateGlfw()
	{
		glfwDestroyWindow(glfwWindow);
		glfwTerminate();
		LOG_INFO(TAG, "GLFW terminated");
	}

}