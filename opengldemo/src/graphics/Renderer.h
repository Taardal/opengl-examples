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
	};
}