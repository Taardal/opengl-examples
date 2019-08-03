#pragma once

namespace Demo
{
	class Shader
	{
	private:
		static std::string tag;
		unsigned int id;

	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		void Bind();
		void Unbind();

	private:
		unsigned int CreateShader(unsigned int shaderType, const std::string& shaderSource);
		void SetShaderSource(unsigned int shaderId, const std::string& shaderSource);
		bool CompileShader(unsigned int shaderId);
		std::string GetShaderLog(unsigned int shaderId);
		unsigned int CreateProgram(unsigned int vertexShaderId, unsigned int fragmentShaderId);
		bool LinkProgram(unsigned int id);
		std::string GetProgramLog(unsigned int programId);
	};
}