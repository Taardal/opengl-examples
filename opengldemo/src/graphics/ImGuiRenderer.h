#pragma once

#include "GraphicsContext.h"
#include "window/WindowProps.h"

namespace Demo
{
	class ImGuiRenderer
	{
	private:
		std::string tag;
		GLFWwindow* glfwWindow;
		WindowProps windowProps;
		float time = 0.0f;

	public:
		ImGuiRenderer(GLFWwindow* glfwWindow, const WindowProps& windowProps);
		~ImGuiRenderer();

		void Begin();
		void End();

	private:
		void SetConfig();
		void InitImplementations();
		void SetStyle();
		void RenderPlatformWindows();
	};
}