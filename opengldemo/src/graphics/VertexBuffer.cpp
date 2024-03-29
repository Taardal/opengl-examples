#include "pch.h"
#include "VertexBuffer.h"
#include <GL/glew.h>

namespace Demo
{
	VertexBuffer::VertexBuffer(float* vertices, unsigned int size, unsigned int vertexLength)
		: id(0), count(size / sizeof(unsigned int) / vertexLength), layout{}
	{
		glCreateBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	unsigned int VertexBuffer::GetCount() const
	{
		return count;
	}

	const VertexBufferLayout& VertexBuffer::GetLayout() const
	{
		return layout;
	}

	void VertexBuffer::SetLayout(VertexBufferLayout layout)
	{
		this->layout = layout;
	}

}
