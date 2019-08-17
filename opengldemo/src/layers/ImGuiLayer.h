#pragma once

#include "Layer.h"

namespace Demo
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnRender(Renderer* renderer) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override;
	};
}