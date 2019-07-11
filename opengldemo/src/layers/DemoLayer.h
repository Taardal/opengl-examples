#pragma once

#include "Layer.h"

namespace Demo
{
	class DemoLayer : public Layer
	{
	private:
		static std::string tag;

		unsigned int vertexArrayId;
		unsigned int vertexBufferId;
		unsigned int indexBufferId;

	public:
		DemoLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override;
	};
}
