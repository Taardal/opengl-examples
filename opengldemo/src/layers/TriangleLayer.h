#pragma once

#include "Layer.h"
#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"
#include "graphics/IndexBuffer.h"
#include "graphics/Shader.h"

namespace Demo
{
	class TriangleLayer : public Layer
	{
	private:
		VertexArray* vertexArray;
		Shader* shader;

	public:
		TriangleLayer();
		~TriangleLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnRender(Renderer* renderer) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override;
	};
}
