#include "pch.h"
#include "Layer.h"

namespace Demo
{
	Layer::Layer(const std::string& name)
		: tag(TO_STRING(Layer)), name(name)
	{
	}

	const std::string& Layer::GetName() const
	{
		return name;
	}

	std::string Layer::ToString() const
	{
		std::stringstream ss;
		ss << tag << "{name=" << name << "}";
		return ss.str();
	}
}