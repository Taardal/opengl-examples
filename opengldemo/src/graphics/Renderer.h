#pragma once

#include "graphics/VertexArray.h"

namespace Demo
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Begin();
		void End();
		void DrawElements(IndexBuffer* indexBuffer, unsigned int startOffset = 0);
		void DrawArrays(unsigned int vertexCount, unsigned int startOffset = 0);
		void EnableDepthTest();
		void EnableStencilTest();
	};
}