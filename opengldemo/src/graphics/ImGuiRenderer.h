#pragma once

#include "GraphicsContext.h"

namespace Demo
{
	class ImGuiRenderer
	{
	private:
		static std::string tag;
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