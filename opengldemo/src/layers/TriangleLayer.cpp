#include "pch.h"
#include "TriangleLayer.h"
#include "graphics/VertexBuffer.h"
#include "graphics/VertexAttribute.h"
#include <GL/glew.h>

namespace Demo
{
	TriangleLayer::TriangleLayer()
		: Layer(TO_STRING(TriangleLayer))
	{
		vertexArray = new VertexArray();

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};
		VertexBuffer* vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));
		vertexBuffer->SetLayout({
			{ GLSLDataType::Vec3, "in_position" },
			{ GLSLDataType::Vec4, "in_color" }
		});
		vertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[] = { 0, 1, 2 };
		IndexBuffer* indexBuffer = new IndexBuffer(indices, sizeof(indices));
		vertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSource = R"(
			#version 330 core
			
			layout(location = 0) in vec3 in_position;
			layout(location = 1) in vec4 in_color;

			out Vertex {
				vec4 color;
			} out_vertex;

			void main()
			{
				out_vertex.color = in_color;
				gl_Position = vec4(in_position, 1.0);
			}
		)";
		std::string fragmentSource = R"(
			#version 330 core

			in Vertex {
				vec4 color;
			} in_vertex;

			out vec4 out_color;
			
			void main()
			{
				out_color = in_vertex.color;
			}
		)";
		shader = new Shader(vertexSource, fragmentSource);
	}

	TriangleLayer::~TriangleLayer()
	{
		delete shader;
		delete vertexArray;
	}

	void TriangleLayer::OnAttach()
	{
		shader->Bind();
		vertexArray->Bind();
	}

	void TriangleLayer::OnDetach()
	{
		shader->Unbind();
		vertexArray->Unbind();
	}

	void TriangleLayer::OnUpdate()
	{
	}

	void TriangleLayer::OnRender(Renderer* renderer)
	{
		renderer->DrawElements(vertexArray->GetIndexBuffer());
	}

	void TriangleLayer::OnImGuiRender()
	{
	}

	void TriangleLayer::OnEvent(const Event& event)
	{
	}
}