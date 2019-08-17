#include "pch.h"
#include "LayerStack.h"

namespace Demo
{
	LayerStack::LayerStack()
		: layerInsertIndex(0)
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		LOG_DEBUG(TAG, "Pushing layer: {0}", layer->ToString());
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		layerInsertIndex++;
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		LOG_DEBUG(TAG, "Popping layer: {0}", layer->ToString());
		auto iterator = std::find(layers.begin(), layers.begin() + layerInsertIndex, layer);
		if (iterator != layers.end())
		{
			layer->OnDetach();
			layers.erase(iterator);
			layerInsertIndex--;
		}
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		LOG_DEBUG(TAG, "Pushing overlay: {0}", layer->ToString());
		layers.emplace_back(layer);
		layer->OnAttach();
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		LOG_DEBUG(TAG, "Popping overlay: {0}", layer->ToString());
		auto iterator = std::find(layers.begin() + layerInsertIndex, layers.end(), layer);
		if (iterator != layers.end())
		{
			layer->OnDetach();
			layers.erase(iterator);
			layerInsertIndex--;
		}
	}

	std::vector<Layer*>::iterator LayerStack::begin()
	{
		return layers.begin();
	}

	std::vector<Layer*>::iterator LayerStack::end()
	{
		return layers.end();
	}
}