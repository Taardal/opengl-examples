#include "pch.h"
#include "Renderer.h"
#include <GL/glew.h>

namespace Demo
{
	Renderer::Renderer()
	{
		LOG_TRACE(TAG, "Created");
	}

	Renderer::~Renderer()
	{
		LOG_TRACE(TAG, "Destroyed");
	}

	void Renderer::Begin()
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::End()
	{
	}

	void Renderer::DrawElements(IndexBuffer* indexBuffer, unsigned int startOffset)
	{
		glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, (const void*) startOffset);
	}
}