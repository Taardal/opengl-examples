#include "pch.h"
#include "DepthAndStencilBufferLayer.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Demo
{
	DepthAndStencilBufferLayer::DepthAndStencilBufferLayer()
		: Layer(TO_STRING(DepthAndStencilBufferLayer))
	{
		vertexArray = new VertexArray();

		float vertices[] = {
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
												   
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
												   
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
												   
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
												   
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
												  
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f

			-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			 1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			 1.0f,  1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			 1.0f,  1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			-1.0f,  1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f
		};
		unsigned int vertexLength = 9;
		VertexBuffer* vertexBuffer = new VertexBuffer(vertices, sizeof(vertices), vertexLength);
		vertexBuffer->SetLayout({
			{ GLSLDataType::Vec3, "in_position" },
			{ GLSLDataType::Vec4, "in_color" },
			{ GLSLDataType::Vec2, "in_textureCoordinate"}
		});
		vertexArray->AddVertexBuffer(vertexBuffer);

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
				vec4 textureColor = mix(kittenColor, puppyColor, 0.5);
				out_color = in_vertex.color * textureColor;
			}
		)";
		shader = new Shader(vertexSource, fragmentSource);

		bool flippedVertically = false;
		kittenTexture = new Texture("assets/kitten.png", flippedVertically);
		puppyTexture = new Texture("assets/puppy.png", flippedVertically);
	}

	DepthAndStencilBufferLayer::~DepthAndStencilBufferLayer()
	{
		delete puppyTexture;
		delete kittenTexture;
		delete shader;
		delete vertexArray;
	}
	
	void DepthAndStencilBufferLayer::OnAttach()
	{
		startTime = std::chrono::high_resolution_clock::now();
	}

	void DepthAndStencilBufferLayer::OnDetach()
	{
		puppyTexture->Unbind();
		kittenTexture->Unbind();
		shader->Unbind();
		vertexArray->Unbind();
	}

	void DepthAndStencilBufferLayer::OnUpdate()
	{
	}

	void DepthAndStencilBufferLayer::OnRender(Renderer* renderer)
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

		VertexBuffer* vertexBuffer = vertexArray->GetVertexBuffers().front();
		{
			unsigned int vertexCount = 36;
			unsigned int startOffset = 0;
			renderer->DrawArrays(vertexCount, startOffset);
		}
	}

	void DepthAndStencilBufferLayer::OnImGuiRender()
	{

	}

	void DepthAndStencilBufferLayer::OnEvent(const Event& event)
	{

	}

	const glm::mat4& DepthAndStencilBufferLayer::GetModelMatrix()
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		float elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - startTime).count();
		float angle = elapsedTime * glm::radians(90.0f);
		glm::vec3 axis = glm::vec3(0.0f, 0.0f, 1.0f);
		return glm::rotate(glm::mat4(1.0f), angle, axis);
	}

	const glm::mat4& DepthAndStencilBufferLayer::GetViewMatrix()
	{
		glm::vec3 cameraPosition = glm::vec3(1.2f, 1.2f, 1.2f);
		glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 upAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		return glm::lookAt(cameraPosition, center, upAxis);
	}

	const glm::mat4& DepthAndStencilBufferLayer::GetProjectionMatrix()
	{
		constexpr float fieldOfView = glm::radians(45.0f);
		float aspectRatio = 800.0f / 600.0f;
		float nearClippingPlane = 1.0f;
		float farClippingPlane = 10.0f;
		return glm::perspective(fieldOfView, aspectRatio, nearClippingPlane, farClippingPlane);
	}
}