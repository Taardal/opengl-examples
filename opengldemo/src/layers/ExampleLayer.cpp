#include "pch.h"
#include "ExampleLayer.h"

#include <GL/glew.h>

namespace Demo
{
	std::string ExampleLayer::tag = TO_STRING(ExampleLayer);

	ExampleLayer::ExampleLayer()
		: Layer(TO_STRING(ExampleLayer)), vertexArrayId(0), vertexBufferId(0), indexBufferId(0)
	{
		glGenVertexArrays(1, &vertexArrayId);
		glBindVertexArray(vertexArrayId);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		glGenBuffers(1, &vertexBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		unsigned int indices[3] = {
			0, 1, 2
		};
		glGenBuffers(1, &indexBufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexShaderSource = R"(
			#version 330 core
			
			layout(location = 0) in vec3 positionAttribute;

			void main()
			{
				gl_Position = vec4(positionAttribute, 1.0);
			}
		)";
		std::string fragmentShaderSource = R"(
			#version 330 core
			
			layout(location = 0) out vec4 colorOutput;

			void main()
			{
				colorOutput = vec4(0.8, 0.2, 0.3, 1.0);
			}
		)";
		shader = new Shader(vertexShaderSource, fragmentShaderSource);
	}

	ExampleLayer::~ExampleLayer()
	{
		delete shader;
	}

	void ExampleLayer::OnAttach()
	{
	}

	void ExampleLayer::OnDetach()
	{
	}

	void ExampleLayer::OnUpdate()
	{
	}

	void ExampleLayer::OnRender()
	{
		shader->Bind();
		glBindVertexArray(vertexArrayId);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}

	void ExampleLayer::OnImGuiRender()
	{
	}

	void ExampleLayer::OnEvent(const Event& event)
	{
	}
}