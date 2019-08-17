#pragma once
#include "VertexBufferLayout.h"

namespace Demo
{
	class VertexBuffer
	{
	private:
		unsigned int id;
		VertexBufferLayout layout;

	public:
		VertexBuffer(float* vertices, unsigned int size);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
		const VertexBufferLayout& GetLayout() const;
		void SetLayout(VertexBufferLayout layout);
	};
}