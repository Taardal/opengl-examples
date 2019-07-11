#include "pch.h"
#include "DemoLayer.h"

#include <GL/glew.h>

namespace Demo
{
	std::string DemoLayer::tag = TO_STRING(DemoLayer);

	DemoLayer::DemoLayer()
		: Layer(TO_STRING(DemoLayer)), vertexArrayId(0), vertexBufferId(0), indexBufferId(0)
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
	}

	void DemoLayer::OnAttach()
	{
	}

	void DemoLayer::OnDetach()
	{
	}

	void DemoLayer::OnUpdate()
	{
	}

	void DemoLayer::OnRender()
	{
		glBindVertexArray(vertexArrayId);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}

	void DemoLayer::OnImGuiRender()
	{
	}

	void DemoLayer::OnEvent(const Event& event)
	{
	}
}