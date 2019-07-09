#include "pch.h"
#include "ImGuiRenderer.h"

#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

namespace Demo
{
	ImGuiRenderer::ImGuiRenderer(GLFWwindow* glfwWindow, const WindowProps& windowProps)
		: tag(TO_STRING(ImGuiRenderer)), glfwWindow(glfwWindow), windowProps(windowProps)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		SetConfig();
		InitImplementations();
		SetStyle();
		LOG_TRACE(tag, "Created");
	}

	ImGuiRenderer::~ImGuiRenderer()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		LOG_TRACE(tag, "Destroyed");
	}

	void ImGuiRenderer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiRenderer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)windowProps.Width, (float)windowProps.Height);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			RenderPlatformWindows();
		}
	}

	void ImGuiRenderer::SetConfig()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	}

	void ImGuiRenderer::InitImplementations()
	{
		bool installCallbacks = true;
		ImGui_ImplGlfw_InitForOpenGL(glfwWindow, installCallbacks);
		const char* glslVersion = "#version 410";
		ImGui_ImplOpenGL3_Init(glslVersion);
	}

	void ImGuiRenderer::SetStyle()
	{
		ImGui::StyleColorsDark();
		ImGuiStyle& style = ImGui::GetStyle();
		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
	}

	void ImGuiRenderer::RenderPlatformWindows()
	{
		GLFWwindow* previousContext = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(previousContext);
	}
}