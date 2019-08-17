#pragma once

#include "GraphicsContext.h"

namespace Demo
{
	class ImGuiRenderer
	{
	private:
		GLFWwindow* glfwWindow;

	public:
		ImGuiRenderer();
		~ImGuiRenderer();

		void Begin();
		void End(float windowWidth, float windowHeight);

	private:
		void SetConfig();
		void InitImplementations();
		void SetStyle();
		void RenderPlatformWindows();
	};
}