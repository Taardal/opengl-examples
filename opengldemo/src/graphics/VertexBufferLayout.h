#pragma once

namespace Demo
{
	enum class ShaderDataType
	{
		None = 0,
		Float,
		Float2,
		Float3,
		Float4,
		Mat3,
		Mat4,
		Int,
		Int2,
		Int3,
		Int4,
		Bool
	};

	static unsigned int ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:
			return sizeof(float);
		case ShaderDataType::Float2:
			return sizeof(float) * 2;
		case ShaderDataType::Float3:
			return sizeof(float) * 3;
		case ShaderDataType::Float4:
			return sizeof(float) * 4;
		case ShaderDataType::Mat3:
			return sizeof(float) * 3 * 3;
		case ShaderDataType::Mat4:
			return sizeof(float) * 4 * 4;
		case ShaderDataType::Int:
			return sizeof(int);
		case ShaderDataType::Int2:
			return sizeof(int) * 2;
		case ShaderDataType::Int3:
			return sizeof(int) * 3;
		case ShaderDataType::Int4:
			return sizeof(int) * 4;
		case ShaderDataType::Bool:
			return sizeof(bool);
		}
	}

	struct VertexBufferElement
	{
		std::string Name;
		ShaderDataType Type;
		unsigned int Size;
		unsigned int Offset;
		bool Normalized;

		VertexBufferElement(ShaderDataType type, const std::string& name);
		unsigned int GetComponentCount() const;
	};

	class VertexBufferLayout
	{
	private:
		std::vector<VertexBufferElement> elements;
		unsigned int stride;

	public:
		VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements);
		~VertexBufferLayout();

		const std::vector<VertexBufferElement>& GetElements() const;
		const unsigned int GetStride() const;
		std::vector<VertexBufferElement>::iterator begin();
		std::vector<VertexBufferElement>::iterator end();
		std::vector<VertexBufferElement>::const_iterator begin() const;
		std::vector<VertexBufferElement>::const_iterator end() const;

	private:
		void CalculateOffsetsAndStride();
	};
}
