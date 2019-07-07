#pragma once

#include "events/Event.h"

namespace Demo
{
	class Layer
	{
	private:
		std::string tag;
		std::string name;

	public:
		Layer(const std::string& name);
		virtual ~Layer() = default;

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void Update();
		virtual void OnImGuiRender();
		virtual void OnEvent(const Event& event);

		const std::string& GetName() const;
		std::string ToString() const;
	};
}