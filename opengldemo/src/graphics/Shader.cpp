#include "pch.h"
#include "Shader.h"
#include <GL/glew.h>

namespace Demo
{
	std::string Shader::tag = TO_STRING(Shader);

	Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		unsigned int vertexShaderId = CreateShader(GL_VERTEX_SHADER, vertexSource);
		unsigned int fragmentShaderId = CreateShader(GL_FRAGMENT_SHADER, fragmentSource);
		if (vertexShaderId != 0 && fragmentShaderId != 0)
		{
			id = CreateProgram(vertexShaderId, fragmentShaderId);
		}
		LOG_TRACE(tag, "Created");
	}

	Shader::~Shader()
	{
		glDeleteProgram(id);
		LOG_TRACE(tag, "Created");
	}

	void Shader::Bind()
	{
		glUseProgram(id);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	unsigned int Shader::CreateShader(unsigned int shaderType, const std::string& shaderSource)
	{
		unsigned int shaderId = glCreateShader(shaderType);
		SetShaderSource(shaderId, shaderSource);
		bool compiled = CompileShader(shaderId);
		if (compiled)
		{
			return shaderId;
		}
		else
		{
			glDeleteShader(shaderId);
			return 0;
		}
	}

	void Shader::SetShaderSource(unsigned int shaderId, const std::string& shaderSource)
	{
		char* source = (char*)shaderSource.c_str();
		unsigned int count = 1;
		int* length = nullptr;
		glShaderSource(shaderId, count, &source, length);
	}

	bool Shader::CompileShader(unsigned int shaderId)
	{
		glCompileShader(shaderId);
		int status = 0;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
		bool compiled = status != 0;
		if (!compiled)
		{
			LOG_ERROR(tag, "Could not compile shader: {0}", GetShaderLog(shaderId));
		}
		return compiled;
	}

	std::string Shader::GetShaderLog(unsigned int shaderId)
	{
		int logLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(shaderId, logLength, &logLength, &log[0]);
		return log.data();
	}

	unsigned int Shader::CreateProgram(unsigned int vertexShaderId, unsigned int fragmentShaderId)
	{
		unsigned int programId = glCreateProgram();
		glAttachShader(programId, vertexShaderId);
		glAttachShader(programId, fragmentShaderId);
		bool linked = LinkProgram(programId);
		if (linked)
		{
			glDetachShader(programId, vertexShaderId);
			glDetachShader(programId, fragmentShaderId);
			return programId;
		}
		else
		{
			glDeleteProgram(programId);
			glDeleteShader(vertexShaderId);
			glDeleteShader(fragmentShaderId);
			return 0;
		}
	}

	bool Shader::LinkProgram(unsigned int programId)
	{
		glLinkProgram(programId);
		int status = 0;
		glGetProgramiv(programId, GL_LINK_STATUS, (int*) &status);
		bool linked = status != 0;
		if (!linked)
		{
			LOG_ERROR(tag, "Could not link shader program: {0}", GetProgramLog(programId));
		}
		return linked;
	}

	std::string Shader::GetProgramLog(unsigned int programId)
	{
		int logLength = 0;
		glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetProgramInfoLog(programId, logLength, &logLength, &log[0]);
		return log.data();
	}
}