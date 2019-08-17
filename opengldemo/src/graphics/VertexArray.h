#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Demo
{
	class VertexArray
	{
	private:
		unsigned int id;
		std::vector<VertexBuffer*> vertexBuffers;
		IndexBuffer* indexBuffer;

	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;
		std::vector<VertexBuffer*> GetVertexBuffers() const;
		void AddVertexBuffer(VertexBuffer* vertexBuffer);
		IndexBuffer* GetIndexBuffer() const;
		void SetIndexBuffer(IndexBuffer* indexBuffer);
	};
}