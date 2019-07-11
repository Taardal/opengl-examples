#pragma once

namespace Demo
{
	class Renderer
	{
	private:
		static std::string tag;

	public:
		Renderer();
		~Renderer();

		void Begin();
		void End();
	};
}