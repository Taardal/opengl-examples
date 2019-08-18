#include "pch.h"
#include "VertexBufferLayout.h"

namespace Demo
{
	VertexBufferLayout::VertexBufferLayout(const std::initializer_list<VertexAttribute>& attributes)
		: attributes(attributes), stride(0)
	{
		for (auto& attribute : this->attributes)
		{
			attribute.Offset = stride;
			stride += attribute.Size;
		}
	}

	const std::vector<VertexAttribute>& VertexBufferLayout::GetAttributes() const
	{
		return attributes;
	}

	const unsigned int VertexBufferLayout::GetStride() const
	{
		return stride;
	}

	std::vector<VertexAttribute>::iterator VertexBufferLayout::begin()
	{
		return attributes.begin();
	}

	std::vector<VertexAttribute>::iterator VertexBufferLayout::end()
	{
		return attributes.end();
	}

	std::vector<VertexAttribute>::const_iterator VertexBufferLayout::begin() const
	{
		return attributes.begin();
	}

	std::vector<VertexAttribute>::const_iterator VertexBufferLayout::end() const
	{
		return attributes.end();
	}
}