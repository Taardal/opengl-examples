#pragma once

#include "VertexBufferLayout.h"

namespace Demo
{
	class VertexBuffer
	{
	private:
		unsigned int id;
		unsigned int count;
		VertexBufferLayout layout;

	public:
		VertexBuffer(float* vertices, unsigned int size, unsigned int vertexLength);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
		unsigned int GetCount() const;
		const VertexBufferLayout& GetLayout() const;
		void SetLayout(VertexBufferLayout layout);
	};
}