#pragma once

#include "events/Event.h"

namespace Demo
{
	class Layer
	{
	private:
		std::string name;

	public:
		Layer(const std::string& name);
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnImGuiRender() = 0;
		virtual void OnEvent(const Event& event) = 0;

		const std::string& GetName() const;
		std::string ToString() const;
	};

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();

		virtual void OnAttach() override {};
		virtual void OnDetach() override {};
		virtual void OnUpdate() override {};
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override {};
	};
}