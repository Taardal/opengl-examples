#include "pch.h"
#include "Application.h"

namespace Demo
{
	Application::Application()
		: tag(TO_STRING(Application)), running(false)
	{
		window = new Window("OpenGL Demo", 640, 480);
		window->SetEventCallback(BIND_FUNCTION(Application::OnEvent));
		layerStack.PushLayer(new ImGuiLayer());
	}

	Application::~Application()
	{
		delete window;
	}

	void Application::Run()
	{
		SetRunning(true);
		while (running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			RenderImGui();
			window->OnUpdate();
		}
	}

	void Application::SetRunning(bool running)
	{
		LOG_DEBUG(tag, "Running: {0}", running);
		this->running = running;
	}

	void Application::RenderImGui()
	{
		ImGuiRenderer* imGuiRenderer = window->GetImGuiRenderer();
		imGuiRenderer->Begin();
		for (Layer* layer : layerStack)
		{
			layer->OnImGuiRender();
		}
		imGuiRenderer->End();
	}

	void Application::OnEvent(const Event& event)
	{
		LOG_DEBUG(tag, "Received event: {0}", event.ToString());
		if (event.GetType() == EventType::WindowClose)
		{
			SetRunning(false);
		}
		else
		{
			OnLayerEvent(event);
		}
	}

	void Application::OnLayerEvent(const Event& event)
	{
		for (auto iterator = layerStack.end(); iterator != layerStack.begin();)
		{
			Layer* layer = *--iterator;
			layer->OnEvent(event);
		}
	}
}
