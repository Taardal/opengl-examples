#pragma once

#include <GL/glew.h>

namespace Demo
{
	enum class GLSLDataType
	{
		None = 0,
		Bool,
		Int,
		Float,
		Vec2,
		Vec3,
		Vec4,
		Mat2,
		Mat3,
		Mat4
	};

	struct VertexAttribute
	{
		std::string Name;
		GLSLDataType ShaderDataType;
		GLenum OpenGLDataType;
		unsigned int Size;
		unsigned int Length;
		unsigned int Offset;
		bool Normalized;

		VertexAttribute(GLSLDataType shaderDataType, const std::string& name);
		
	private:
		GLenum GetOpenGLDataType();
		unsigned int GetSize();
		unsigned int GetLength();
	};
}
