#pragma once

#include "WindowProps.h"
#include "events/Event.h"
#include "graphics/GraphicsContext.h"
#include "graphics/ImGuiRenderer.h"

namespace Demo
{	
	class Window
	{
	private:
		struct WindowData : public WindowProps
		{
			std::function<void(Event&)> OnEvent;
			bool VSync;

			WindowData(const std::string& title, int width, int height)
				: WindowProps({ title, width, height })
			{
			}
		};

	private:
		std::string tag;
		WindowData windowData;
		GLFWwindow* glfwWindow;
		GraphicsContext* graphicsContext;
		ImGuiRenderer* imGuiRenderer;

	public:
		Window(const std::string& title, int width, int height);
		~Window();

		ImGuiRenderer* GetImGuiRenderer() const;
		void SetEventCallback(const std::function<void(Event&)>& onEvent);
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