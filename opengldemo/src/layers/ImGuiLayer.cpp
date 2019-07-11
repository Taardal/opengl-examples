#include "pch.h"
#include "ImGuiLayer.h"

#include <imgui.h>

namespace Demo
{
	ImGuiLayer::ImGuiLayer()
		: Layer(TO_STRING(ImGuiLayer))
	{
	}

	void ImGuiLayer::OnAttach()
	{
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
	}

	void ImGuiLayer::OnRender()
	{
	}

	void ImGuiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void ImGuiLayer::OnEvent(const Event& event)
	{
	}
}