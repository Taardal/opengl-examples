#include "pch.h"
#include "Layer.h"

#include <imgui.h>

namespace Demo
{
	Layer::Layer(const std::string& name)
		: name(name)
	{
	}

	const std::string& Layer::GetName() const
	{
		return name;
	}

	std::string Layer::ToString() const
	{
		std::stringstream ss;
		ss << name << "{}";
		return ss.str();
	}

	ImGuiLayer::ImGuiLayer()
		: Layer(TO_STRING(ImGuiLayer))
	{
	}

	void ImGuiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
}