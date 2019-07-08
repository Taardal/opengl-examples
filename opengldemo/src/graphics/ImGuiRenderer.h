#pragma once

#include "window/WindowProps.h"

namespace Demo
{
	class ImGuiRenderer
	{
	private:
		std::string tag;
		WindowProps windowProps;
		float time = 0.0f;

	public:
		ImGuiRenderer(const WindowProps& windowProps);
		~ImGuiRenderer();

		void Begin();
		void End();

	private:
		void SetConfig();
		void InitImplementations();
		void SetStyle();
	};
}