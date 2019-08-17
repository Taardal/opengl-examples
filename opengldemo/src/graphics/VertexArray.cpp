#include "pch.h"
#include "VertexArray.h"
#include "VertexAttribute.h"
#include <GL/glew.h>

namespace Demo
{
	VertexArray::VertexArray()
		: vertexBuffers{}, indexBuffer(nullptr)
	{
		glCreateVertexArrays(1, &id);
	}

	VertexArray::~VertexArray()
	{
		for (VertexBuffer* vertexBuffer : vertexBuffers)
		{
			delete vertexBuffer;
		}
		if (indexBuffer != nullptr)
		{
			delete indexBuffer;
		}
		glDeleteVertexArrays(1, &id);
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(id);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	std::vector<VertexBuffer*> VertexArray::GetVertexBuffers() const
	{
		return vertexBuffers;
	}

	void VertexArray::AddVertexBuffer(VertexBuffer* vertexBuffer)
	{
		glBindVertexArray(id);
		vertexBuffer->Bind();
		unsigned int index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& vertexAttribute : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				vertexAttribute.Length,
				vertexAttribute.OpenGLDataType,
				vertexAttribute.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)vertexAttribute.Offset
			);
			index++;
		}
		vertexBuffers.push_back(vertexBuffer);
	}

	IndexBuffer* VertexArray::GetIndexBuffer() const
	{
		return indexBuffer;
	}

	void VertexArray::SetIndexBuffer(IndexBuffer* indexBuffer)
	{
		glBindVertexArray(id);
		indexBuffer->Bind();
		this->indexBuffer = indexBuffer;
	}
}