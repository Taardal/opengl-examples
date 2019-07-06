#pragma once

#include "GLFW/glfw3.h"

#include "events/WindowEvent.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

namespace Demo
{	
	class Window
	{
	private:
		using OnEventFn = std::function<void(Event&)>;

		struct WindowData
		{
			std::string Title;
			int Width;
			int Height;
			OnEventFn OnEvent;
		};

		GLFWwindow* glfwWindow;
		WindowData windowData;
		std::string tag;

	public:
		Window(const std::string& title, int width, int height);
		~Window();

		void SetEventCallback(const std::function<void(Event&)>& onEvent);
		void OnUpdate();

	private:
		void InitGlfw();
		void TerminateGlfw();
		GLFWwindow* GetGlfwWindow();
		GLFWwindow* CreateGlfwWindow();
		void SetGlfwCallbacks();
		void SetGlfwWindowCallbacks();
		void SetGlfwKeyCallbacks();
		void SetGlfwMouseCallbacks();
	};
}