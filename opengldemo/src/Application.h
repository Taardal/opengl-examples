#pragma once

#include "window/Window.h"
#include "layers/LayerStack.h"

namespace Demo
{
	class Application
	{
	private:
		Window* window;
		LayerStack layerStack;
		std::string tag;
		bool running;

	public:
		Application();
		~Application();

		void Run();
		void OnEvent(const Event& event);

	private:
		void Stop();
		void RenderImGui();
		void OnLayerEvent(const Event& event);
	};
}

