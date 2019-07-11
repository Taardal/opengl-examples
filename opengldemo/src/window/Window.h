#pragma once

#include "events/Event.h"
#include "graphics/GraphicsContext.h"
#include "graphics/Renderer.h"
#include "graphics/ImGuiRenderer.h"
#include "input/InputPoller.h"

namespace Demo
{	
	class Window
	{
	private:
		struct WindowData
		{
			std::string Title;
			int Width;
			int Height;
			bool VSync;
			std::function<void(const Event&)> OnEvent;
		};

		static std::string tag;
		static bool glfwInitialized;

		WindowData windowData;
		GLFWwindow* glfwWindow;
		GraphicsContext* graphicsContext;

	public:
		Window(const std::string& title, int width, int height);
		~Window();

		void OnUpdate();
		void SetEventListener(const std::function<void(const Event&)>& onEvent);
		float GetWidth() const;
		float GetHeight() const;
		bool IsVync() const;
		void SetVSync(bool vSync);

	private:
		static void OnGlfwError(int error, const char* description);

		void InitGlfw();
		GLFWwindow* CreateGlfwWindow();
		void SetGlfwCallbacks();
		void SetGlfwWindowCallbacks();
		void SetGlfwKeyCallbacks();
		void SetGlfwMouseCallbacks();
		void TerminateGlfw();
	};
}