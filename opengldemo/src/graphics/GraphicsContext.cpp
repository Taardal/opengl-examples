#include "pch.h"
#include "GraphicsContext.h"

namespace Demo
{
	bool GraphicsContext::glewInitialized = false;

	GraphicsContext::GraphicsContext(GLFWwindow* glfwWindow)
		: glfwWindow(glfwWindow)
	{
		glfwMakeContextCurrent(glfwWindow);
		InitGlew();
		LogContext();
		LOG_TRACE(TAG, "Created");
	}

	GraphicsContext::~GraphicsContext()
	{
		LOG_TRACE(TAG, "Destroyed");
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
				LOG_INFO(TAG, "GLEW initialized");
				glewInitialized = true;
			}
			else
			{
				LOG_CRITICAL(TAG, "Could not init GLEW");
			}
		}
	}

	void GraphicsContext::LogContext()
	{
		LOG_INFO(TAG, "Vendor: {0}", glGetString(GL_VENDOR));
		LOG_INFO(TAG, "Renderer: {0}", glGetString(GL_RENDERER));
		LOG_INFO(TAG, "Version: {0}", glGetString(GL_VERSION));
	}
}