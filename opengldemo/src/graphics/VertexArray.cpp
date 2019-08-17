#include "pch.h"
#include "VertexArray.h"
#include <GL/glew.h>

namespace Demo
{
	static GLenum GetOpenGLDataType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:
			return GL_FLOAT;
		case ShaderDataType::Float2:
			return GL_FLOAT;
		case ShaderDataType::Float3:
			return GL_FLOAT;
		case ShaderDataType::Float4:
			return GL_FLOAT;
		case ShaderDataType::Mat3:
			return GL_FLOAT;
		case ShaderDataType::Mat4:
			return GL_FLOAT;
		case ShaderDataType::Int:
			return GL_INT;
		case ShaderDataType::Int2:
			return GL_INT;
		case ShaderDataType::Int3:
			return GL_INT;
		case ShaderDataType::Int4:
			return GL_INT;
		case ShaderDataType::Bool:
			return GL_BOOL;
		}
	}

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
		const VertexBufferLayout& layout = vertexBuffer->GetLayout();
		for (const VertexBufferElement& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				GetOpenGLDataType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset
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