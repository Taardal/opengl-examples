#include "pch.h"
#include "Renderer.h"
#include <GL/glew.h>

namespace Demo
{
	std::string Renderer::tag = TO_STRING(Renderer);

	Renderer::Renderer()
	{
		LOG_TRACE(tag, "Created");
	}

	Renderer::~Renderer()
	{
		LOG_TRACE(tag, "Destroyed");
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