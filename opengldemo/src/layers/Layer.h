#pragma once

#include "graphics/Renderer.h"
#include "events/Event.h"

namespace Demo
{
	class Layer
	{
	private:
		std::string name;

	public:
		Layer(const std::string& name);
		virtual ~Layer();

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender(Renderer* renderer) = 0;
		virtual void OnImGuiRender() = 0;
		virtual void OnEvent(const Event& event) = 0;

		const std::string& GetName() const;
		std::string ToString() const;
	};
}