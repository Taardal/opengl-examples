#pragma once

#include "Layer.h"
#include "graphics/VertexArray.h"
#include "graphics/Shader.h"
#include "graphics/Texture.h"

namespace Demo
{
	class TextureLayer : public Layer
	{
	private:
		VertexArray* vertexArray;
		Shader* shader;
		Texture* texture;

	public:
		TextureLayer();
		~TextureLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnRender(Renderer* renderer) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override;
	};
}
