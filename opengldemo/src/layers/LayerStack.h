#pragma once

#include "Layer.h"

namespace Demo
{
	class LayerStack
	{
	private:
		static std::string tag;

		std::vector<Layer*> layers;
		unsigned int layerInsertIndex;

	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);
		std::vector<Layer*>::iterator begin();
		std::vector<Layer*>::iterator end();
	};
}
