#pragma once

#include "Layer.h"
#include "graphics/VertexArray.h"
#include "graphics/Shader.h"
#include "graphics/Texture.h"

namespace Demo
{
	class Texture3DLayer : public Layer
	{
	private:
		VertexArray* vertexArray;
		Shader* shader;
		Texture* kittenTexture;
		Texture* puppyTexture;
		std::chrono::steady_clock::time_point startTime;

	public:
		Texture3DLayer();
		~Texture3DLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnRender(Renderer* renderer) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(const Event& event) override;

	private:
		const glm::mat4& GetModelMatrix();
		const glm::mat4& GetViewMatrix();
		const glm::mat4& GetProjectionMatrix();
	};
}
