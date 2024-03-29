#pragma once

#include "Window.h"
#include "layers/LayerStack.h"

namespace Demo
{
	class Application
	{
	private:
		Window* window;
		Renderer* renderer;
		ImGuiRenderer* imGuiRenderer;
		InputPoller* inputPoller;
		LayerStack layerStack;
		bool running;

	public:
		Application();
		~Application();

		void PushLayer(Layer* layer);
		void Run();
		void OnEvent(const Event& event);

	private:
		void Stop();
		void Render();
		void RenderImGui();
		void OnLayerEvent(const Event& event);
	};
}

