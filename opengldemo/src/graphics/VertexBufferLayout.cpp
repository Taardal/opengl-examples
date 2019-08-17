#include "pch.h"
#include "VertexBufferLayout.h"

namespace Demo
{
	VertexBufferElement::VertexBufferElement(ShaderDataType type, const std::string& name)
		: Type(type), Name(name), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(false)
	{
	}

	unsigned int VertexBufferElement::GetComponentCount() const
	{
		switch (Type)
		{
		case ShaderDataType::Float:
			return 1;
		case ShaderDataType::Float2:
			return 2;
		case ShaderDataType::Float3:
			return 3;
		case ShaderDataType::Float4:
			return 4;
		case ShaderDataType::Mat3:
			return 3 * 3;
		case ShaderDataType::Mat4:
			return 4 * 4;
		case ShaderDataType::Int:
			return 1;
		case ShaderDataType::Int2:
			return 2;
		case ShaderDataType::Int3:
			return 3;
		case ShaderDataType::Int4:
			return 4;
		case ShaderDataType::Bool:
			return 1;
		}
	}

	VertexBufferLayout::VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements)
		: elements(elements), stride(0)
	{
		CalculateOffsetsAndStride();
	}

	VertexBufferLayout::~VertexBufferLayout()
	{
	}

	const std::vector<VertexBufferElement>& VertexBufferLayout::GetElements() const
	{
		return elements;
	}

	const unsigned int VertexBufferLayout::GetStride() const
	{
		return stride;
	}

	std::vector<VertexBufferElement>::iterator VertexBufferLayout::begin()
	{
		return elements.begin();
	}

	std::vector<VertexBufferElement>::iterator VertexBufferLayout::end()
	{
		return elements.end();
	}

	std::vector<VertexBufferElement>::const_iterator VertexBufferLayout::begin() const
	{
		return elements.begin();
	}

	std::vector<VertexBufferElement>::const_iterator VertexBufferLayout::end() const
	{
		return elements.end();
	}

	void VertexBufferLayout::CalculateOffsetsAndStride()
	{
		for (auto& element : elements)
		{
			element.Offset = stride;
			stride += element.Size;
		}
	}
}