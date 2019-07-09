#include "pch.h"
#include "Window.h"
#include "events/WindowEvent.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

namespace Demo
{
	bool Window::glfwInitialized = false;

	Window::Window(const std::string& title, int width, int height)
		: tag(TO_STRING(Window)), windowData(title, width, height)
	{
		Init();
		graphicsContext = new GraphicsContext(glfwWindow);
		imGuiRenderer = new ImGuiRenderer(glfwWindow, windowData);
		inputPoller = new InputPoller(glfwWindow);
		LOG_TRACE(tag, "Created");
	}

	Window::~Window()
	{
		delete inputPoller;
		delete imGuiRenderer;
		delete graphicsContext;
		TerminateGlfw();
		LOG_TRACE(tag, "Destroyed");
	}

	ImGuiRenderer* Window::GetImGuiRenderer() const
	{
		return imGuiRenderer;
	}

	InputPoller* Window::GetInputPoller() const
	{
		return inputPoller;
	}

	void Window::SetEventCallback(const std::function<void(const Event&)>& onEvent)
	{
		windowData.OnEvent = onEvent;
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

	void Window::OnUpdate()
	{
		graphicsContext->SwapBuffers();
		glfwPollEvents();
	}

	void Window::Init()
	{
		InitGlfw();
		glfwWindow = GetGlfwWindow();
		glfwSetWindowUserPointer(glfwWindow, &windowData);
		SetGlfwCallbacks();
	}

	void Window::InitGlfw()
	{
		if (!glfwInitialized)
		{
			if (glfwInit() == GLFW_TRUE)
			{
				glfwSetErrorCallback(OnGlfwError);
				glfwInitialized = true;
			}
			else
			{
				LOG_CRITICAL(tag, "Could not init GLFW");
			}
		}
	}

	GLFWwindow* Window::GetGlfwWindow()
	{
		GLFWwindow* glfwWindow = CreateGlfwWindow();
		if (!glfwWindow)
		{
			LOG_CRITICAL(tag, "Could not create GLFW window");
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
		glfwSetCursorPosCallback(glfwWindow, [](GLFWwindow* glfwWindow, double xpos, double ypos)
		{
			WindowData* windowData = (WindowData*)glfwGetWindowUserPointer(glfwWindow);
			MouseMovedEvent event((float) xpos, (float) ypos);
			windowData->OnEvent(event);
		});
	}

	void Window::TerminateGlfw()
	{
		glfwTerminate();
		LOG_DEBUG(tag, "Terminated GLFW");
	}

	void Window::OnGlfwError(int error, const char* description)
	{
		LOG_ERROR(TO_STRING(Window), "GLFW error ({0}): {1}", error, description);
	}

}