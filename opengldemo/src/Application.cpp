#include "pch.h"
#include "Application.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

namespace Demo
{
	Application::Application()
		: tag(TO_STRING(Application)), running(false)
	{
		window = new Window("OpenGL Demo", 640, 480);
		window->SetEventCallback(BIND_FUNCTION(Application::OnEvent));
		layerStack.PushLayer(new ImGuiLayer());
		LOG_TRACE(tag, "Created");
	}

	Application::~Application()
	{
		delete window;
		LOG_TRACE(tag, "Destroyed");
	}

	void Application::Run()
	{
		LOG_DEBUG(tag, "Running");
		running = true;
		while (running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			RenderImGui();
			window->OnUpdate();
		}
	}

	void Application::Stop()
	{
		LOG_DEBUG(tag, "Stopping");
		this->running = false;
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
			Stop();
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
