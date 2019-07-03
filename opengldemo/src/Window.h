#pragma once

#include "GLFW/glfw3.h"

namespace Demo
{
	struct WindowData
	{
		std::string Title;
		int Width;
		int Height;
		bool ShouldClose;
	};

	class Window
	{
	private:
		GLFWwindow* glfwWindow;
		WindowData windowData;

	public:
		Window(std::string title, int width, int height);
		~Window();

		void OnUpdate();
		bool ShouldClose();

	private:
		void Init();
		void Shutdown();
		GLFWwindow* CreateGlfwWindow();
	};
}