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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1);
	}

	void Renderer::End()
	{
	}
}