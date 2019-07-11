#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Demo
{
	class GraphicsContext
	{
	private:
		static std::string tag;
		static bool glewInitialized;

		GLFWwindow* glfwWindow;

	public:
		GraphicsContext(GLFWwindow* glfwWindow);
		~GraphicsContext();

		void SwapBuffers();

	private:
		void InitGlew();
		void LogContext();
	};
}