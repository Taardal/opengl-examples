#include "pch.h"
#include "Layer.h"

namespace Demo
{
	Layer::Layer(const std::string& name)
		: name(name)
	{
	}

	Layer::~Layer()
	{
	}

	const std::string& Layer::GetName() const
	{
		return name;
	}

	std::string Layer::ToString() const
	{
		std::stringstream ss;
		ss << name << "{}";
		return ss.str();
	}
}