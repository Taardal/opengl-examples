#include "pch.h"
#include "ExampleLayer.h"
#include "graphics/VertexBuffer.h"
#include "graphics/VertexAttribute.h"
#include <GL/glew.h>

namespace Demo
{
	std::string ExampleLayer::tag = TO_STRING(ExampleLayer);

	ExampleLayer::ExampleLayer()
		: Layer(TO_STRING(ExampleLayer))
	{
		vertexArray = new VertexArray();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};
		VertexBuffer* vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));
		vertexBuffer->SetLayout({
			{ GLSLDataType::Vec3, "positionAttribute" },
			{ GLSLDataType::Vec4, "colorAttribute" }
		});
		vertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		IndexBuffer* indexBuffer = new IndexBuffer(indices, sizeof(indices));
		vertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexShaderSource = R"(
			#version 330 core
			
			layout(location = 0) in vec3 positionAttribute;
			layout(location = 1) in vec4 colorAttribute;

			out vec4 v_Color;

			void main()
			{
				v_Color = colorAttribute;
				gl_Position = vec4(positionAttribute, 1.0);
			}
		)";
		std::string fragmentShaderSource = R"(
			#version 330 core
			
			layout(location = 0) out vec4 colorOutput;

			in vec4 v_Color;

			void main()
			{
				colorOutput = vec4(0.8, 0.2, 0.3, 1.0);
				colorOutput = v_Color;
			}
		)";
		shader = new Shader(vertexShaderSource, fragmentShaderSource);
	}

	ExampleLayer::~ExampleLayer()
	{
		delete shader;
		delete vertexArray;
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
		vertexArray->Bind();
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}

	void ExampleLayer::OnImGuiRender()
	{
	}

	void ExampleLayer::OnEvent(const Event& event)
	{
	}
}