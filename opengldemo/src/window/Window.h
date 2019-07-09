#pragma once

#include "WindowProps.h"
#include "events/Event.h"
#include "graphics/GraphicsContext.h"
#include "graphics/ImGuiRenderer.h"
#include "input/InputPoller.h"

namespace Demo
{	
	class Window
	{
	private:
		struct WindowData : public WindowProps
		{
			std::function<void(const Event&)> OnEvent;
			bool VSync;

			WindowData(const std::string& title, int width, int height)
				: WindowProps({ title, width, height }), VSync(false)
			{
			}
		};

	private:
		std::string tag;
		WindowData windowData;
		GLFWwindow* glfwWindow;
		GraphicsContext* graphicsContext;
		ImGuiRenderer* imGuiRenderer;
		InputPoller* inputPoller;
		static bool glfwInitialized;

	public:
		Window(const std::string& title, int width, int height);
		~Window();

		ImGuiRenderer* GetImGuiRenderer() const;
		InputPoller* GetInputPoller() const;
		void SetEventCallback(const std::function<void(const Event&)>& onEvent);
		bool IsVync() const;
		void SetVSync(bool vSync);
		void OnUpdate();

	private:
		void Init();
		void InitGlfw();
		GLFWwindow* GetGlfwWindow();
		GLFWwindow* CreateGlfwWindow();
		void SetGlfwCallbacks();
		void SetGlfwWindowCallbacks();
		void SetGlfwKeyCallbacks();
		void SetGlfwMouseCallbacks();
		void TerminateGlfw();
		static void OnGlfwError(int error, const char* description);
	};
}