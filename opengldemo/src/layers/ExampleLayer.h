#pragma once

#include "Layer.h"
#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"
#include "graphics/IndexBuffer.h"
#include "graphics/Shader.h"

namespace Demo
{
	class ExampleLayer : public Layer
	{
	private:
		VertexArray* vertexArray;
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
