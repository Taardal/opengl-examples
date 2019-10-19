#include "pch.h"
#include "IndexBuffer.h"
#include <GL/glew.h>

namespace Demo
{
	IndexBuffer::IndexBuffer(unsigned int* indices, unsigned int size)
		: id(0), count(size / sizeof(unsigned int))
	{
		glCreateBuffers(1, &id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	unsigned int IndexBuffer::GetCount() const
	{
		return count;
	}
}