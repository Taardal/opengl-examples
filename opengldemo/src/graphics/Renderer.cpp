#include "pch.h"
#include "Renderer.h"
#include <GL/glew.h>

namespace Demo
{
	Renderer::Renderer()
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1);
		EnableDepthTest();
		EnableStencilTest();
		LOG_TRACE(TAG, "Created");
	}

	Renderer::~Renderer()
	{
		LOG_TRACE(TAG, "Destroyed");
	}

	void Renderer::Begin()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::End()
	{
	}

	void Renderer::DrawElements(IndexBuffer* indexBuffer, unsigned int startOffset)
	{
		glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, (const void*) startOffset);
	}

	void Renderer::DrawArrays(unsigned int vertexCount, unsigned int startOffset)
	{
		glDrawArrays(GL_TRIANGLES, startOffset, vertexCount);
	}

	void Renderer::EnableDepthTest()
	{
		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::EnableStencilTest()
	{
		glEnable(GL_STENCIL_TEST);
	}
}