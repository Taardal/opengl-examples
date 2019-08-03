#include "pch.h"
#include "Application.h"
#include "layers/ExampleLayer.h"
#include "layers/ImGuiLayer.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

namespace Demo
{
	std::string Application::tag = TO_STRING(Application);

	Application::Application()
		: running(false)
	{
		window = new Window("OpenGL Demo", 640, 480);
		window->SetEventListener(BIND_FUNCTION(Application::OnEvent));
		renderer = new Renderer();
		imGuiRenderer = new ImGuiRenderer();
		inputPoller = new InputPoller();
		layerStack.PushLayer(new ExampleLayer());
		layerStack.PushOverlay(new ImGuiLayer());
		LOG_TRACE(tag, "Created");
	}

	Application::~Application()
	{
		delete inputPoller;
		delete imGuiRenderer;
		delete renderer;
		delete window;
		LOG_TRACE(tag, "Destroyed");
	}

	void Application::Run()
	{
		LOG_DEBUG(tag, "Running");
		running = true;
		while (running)
		{
			Render();
			RenderImGui();
			window->OnUpdate();
		}
	}

	void Application::Stop()
	{
		LOG_DEBUG(tag, "Stopping");
		this->running = false;
	}

	void Application::Render()
	{
		renderer->Begin();
		for (Layer* layer : layerStack)
		{
			layer->OnRender();
		}
		renderer->End();
	}

	void Application::RenderImGui()
	{
		imGuiRenderer->Begin();
		for (Layer* layer : layerStack)
		{
			layer->OnImGuiRender();
		}
		imGuiRenderer->End(window->GetWidth(), window->GetHeight());
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
