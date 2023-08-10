#include "pch.h"
#include "Texture3DLayer.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Demo
{
	Texture3DLayer::Texture3DLayer()
		: Layer(TO_STRING(Texture3DLayer))
	{
		vertexArray = new VertexArray();

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f, 0.0f, 1.0f
		};
		unsigned int vertexLength = 9;
		VertexBuffer* vertexBuffer = new VertexBuffer(vertices, sizeof(vertices), vertexLength);
		vertexBuffer->SetLayout({
			{ GLSLDataType::Vec3, "in_position" },
			{ GLSLDataType::Vec4, "in_color" },
			{ GLSLDataType::Vec2, "in_textureCoordinate"}
		});
		vertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};
		IndexBuffer* indexBuffer = new IndexBuffer(indices, sizeof(indices));
		vertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSource = R"(
			#version 330 core
			
			layout(location = 0) in vec3 in_position;
			layout(location = 1) in vec4 in_color;
			layout(location = 2) in vec2 in_textureCoordinate;

			uniform mat4 modelMatrix;
			uniform mat4 viewMatrix;
			uniform mat4 projectionMatrix;

			out Vertex {
				vec4 color;
				vec2 textureCoordinate;
			} out_vertex;

			void main()
			{
				out_vertex.color = in_color;
				out_vertex.textureCoordinate = in_textureCoordinate;
				gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_position, 1.0);
			}
		)";
		std::string fragmentSource = R"(
			#version 330 core

			in Vertex {
				vec4 color;
				vec2 textureCoordinate;
			} in_vertex;

			uniform sampler2D kittenSampler;
			uniform sampler2D puppySampler;

			out vec4 out_color;
			
			void main()
			{
				vec4 kittenColor = texture(kittenSampler, in_vertex.textureCoordinate);
				vec4 puppyColor = texture(puppySampler, in_vertex.textureCoordinate);
				out_color = mix(kittenColor, puppyColor, 0.5);
			}
		)";
		shader = new Shader(vertexSource, fragmentSource);

		bool flippedVertically = true;
		kittenTexture = new Texture("assets/kitten.png", flippedVertically);
		puppyTexture = new Texture("assets/puppy.png", flippedVertically);
	}

	Texture3DLayer::~Texture3DLayer()
	{
		delete puppyTexture;
		delete kittenTexture;
		delete shader;
		delete vertexArray;
	}

	void Texture3DLayer::OnAttach()
	{
		startTime = std::chrono::high_resolution_clock::now();
	}

	void Texture3DLayer::OnDetach()
	{
		puppyTexture->Unbind();
		kittenTexture->Unbind();
		shader->Unbind();
		vertexArray->Unbind();
	}

	void Texture3DLayer::OnUpdate()
	{
	}

	void Texture3DLayer::OnRender(Renderer* renderer)
	{
		vertexArray->Bind();
		shader->Bind();
		{
			int textureUnit = 0;
			kittenTexture->Bind(textureUnit);
			shader->SetUniform1i("kittenSampler", textureUnit);
		}
		{
			int textureUnit = 1;
			puppyTexture->Bind(textureUnit);
			shader->SetUniform1i("puppySampler", textureUnit);
		}
		shader->SetUniformMat4f("modelMatrix", GetModelMatrix());
		shader->SetUniformMat4f("viewMatrix", GetViewMatrix());
		shader->SetUniformMat4f("projectionMatrix", GetProjectionMatrix());
		renderer->DrawElements(vertexArray->GetIndexBuffer());
	}

	void Texture3DLayer::OnImGuiRender()
	{
	}

	void Texture3DLayer::OnEvent(const Event& event)
	{
	}

	const glm::mat4& Texture3DLayer::GetModelMatrix()
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		float elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - startTime).count();
		float angle = elapsedTime * glm::radians(90.0f);
		glm::vec3 axis = glm::vec3(0.0f, 0.0f, 1.0f);
		return glm::rotate(glm::mat4(1.0f), angle, axis);
	}

	const glm::mat4& Texture3DLayer::GetViewMatrix()
	{
		glm::vec3 cameraPosition = glm::vec3(1.2f, 1.2f, 1.2f);
		glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 upAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		return glm::lookAt(cameraPosition, center, upAxis);
	}

	const glm::mat4& Texture3DLayer::GetProjectionMatrix()
	{
		constexpr float fieldOfView = glm::radians(45.0f);
		float aspectRatio = 800.0f / 600.0f;
		float nearClippingPlane = 1.0f;
		float farClippingPlane = 10.0f;
		return glm::perspective(fieldOfView, aspectRatio, nearClippingPlane, farClippingPlane);
	}
}