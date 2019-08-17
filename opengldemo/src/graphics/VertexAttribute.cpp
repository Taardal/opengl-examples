#include "pch.h"
#include "VertexAttribute.h"

namespace Demo
{
	VertexAttribute::VertexAttribute(GLSLDataType shaderDataType, const std::string& name)
		: Name(name), ShaderDataType(shaderDataType), OpenGLDataType(GetOpenGLDataType()), Size(GetSize()), Length(GetLength()), Offset(0), Normalized(false)
	{
	}

	GLenum VertexAttribute::GetOpenGLDataType()
	{
		switch (ShaderDataType)
		{
		case GLSLDataType::Bool:
			return GL_BOOL;
		case GLSLDataType::Int:
			return GL_INT;
		case GLSLDataType::Float:
			return GL_FLOAT;
		case GLSLDataType::Vec2:
			return GL_FLOAT;
		case GLSLDataType::Vec3:
			return GL_FLOAT;
		case GLSLDataType::Vec4:
			return GL_FLOAT;
		case GLSLDataType::Mat2:
			return GL_FLOAT;
		case GLSLDataType::Mat3:
			return GL_FLOAT;
		case GLSLDataType::Mat4:
			return GL_FLOAT;
		}
	}

	unsigned int VertexAttribute::GetSize()
	{
		switch (ShaderDataType)
		{
		case GLSLDataType::Bool:
			return sizeof(bool);
		case GLSLDataType::Int:
			return sizeof(int);
		case GLSLDataType::Float:
			return sizeof(float);
		case GLSLDataType::Vec2:
			return sizeof(float) * 2;
		case GLSLDataType::Vec3:
			return sizeof(float) * 3;
		case GLSLDataType::Vec4:
			return sizeof(float) * 4;
		case GLSLDataType::Mat2:
			return sizeof(float) * 2 * 2;
		case GLSLDataType::Mat3:
			return sizeof(float) * 3 * 3;
		case GLSLDataType::Mat4:
			return sizeof(float) * 4 * 4;
		}
	}

	unsigned int VertexAttribute::GetLength()
	{
		switch (ShaderDataType)
		{
		case GLSLDataType::Bool:
			return 1;
		case GLSLDataType::Int:
			return 1;
		case GLSLDataType::Float:
			return 1;
		case GLSLDataType::Vec2:
			return 2;
		case GLSLDataType::Vec3:
			return 3;
		case GLSLDataType::Vec4:
			return 4;
		case GLSLDataType::Mat2:
			return 2 * 2;
		case GLSLDataType::Mat3:
			return 3 * 3;
		case GLSLDataType::Mat4:
			return 4 * 4;
		}
	}
}