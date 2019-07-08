#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Demo
{
	class GraphicsContext
	{
	private:
		std::string tag;
		GLFWwindow* glfwWindow;

	public:
		GraphicsContext(GLFWwindow* glfwWindow);

		void SwapBuffers();

	private:
		void InitGlew();
		void LogOpenGLInfo();
	};
}