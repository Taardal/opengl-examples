#pragma once

#include "VertexAttribute.h"

namespace Demo
{
	class VertexBufferLayout
	{
	private:
		std::vector<VertexAttribute> attributes;
		unsigned int stride;

	public:
		VertexBufferLayout(const std::initializer_list<VertexAttribute>& attributes);
		~VertexBufferLayout() = default;

		const std::vector<VertexAttribute>& GetAttributes() const;
		const unsigned int GetStride() const;
		std::vector<VertexAttribute>::iterator begin();
		std::vector<VertexAttribute>::iterator end();
		std::vector<VertexAttribute>::const_iterator begin() const;
		std::vector<VertexAttribute>::const_iterator end() const;
	};
}