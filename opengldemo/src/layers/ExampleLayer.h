#pragma once

#include "Layer.h"
#include "graphics/Shader.h"

namespace Demo
{
	class ExampleLayer : public Layer
	{
	private:
		static std::string tag;

		unsigned int vertexArrayId;
		unsigned int vertexBufferId;
		unsigned int indexBufferId;
		Shader* shader;

	public:
		ExampleLayer();
		~ExampleLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override;
	};
}
