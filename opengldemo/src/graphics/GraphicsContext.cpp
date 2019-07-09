#include "pch.h"
#include "GraphicsContext.h"

namespace Demo
{
	static bool glewInitialized = false;

	GraphicsContext::GraphicsContext(GLFWwindow* glfwWindow)
		: tag(TO_STRING(GraphicsContext)), glfwWindow(glfwWindow)
	{
		glfwMakeContextCurrent(glfwWindow);
		InitGlew();
		LogOpenGLInfo();
		LOG_TRACE(tag, "Created");
	}

	GraphicsContext::~GraphicsContext()
	{
		LOG_TRACE(tag, "Destroyed");
	}

	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(glfwWindow);
	}

	void GraphicsContext::InitGlew()
	{
		if (!glewInitialized)
		{
			if (glewInit() == GLEW_OK)
			{
				glewInitialized = true;
			}
			else
			{
				LOG_CRITICAL(tag, "Could not init GLEW");
			}
		}
	}

	void GraphicsContext::LogOpenGLInfo()
	{
		LOG_INFO(tag, "OpenGL Info:");
		LOG_INFO(tag, "Vendor: {0}", glGetString(GL_VENDOR));
		LOG_INFO(tag, "Renderer: {0}", glGetString(GL_RENDERER));
		LOG_INFO(tag, "Version: {0}", glGetString(GL_VERSION));
	}
}