#include "pch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Demo
{
	std::shared_ptr<spdlog::logger> Log::logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		logger = spdlog::stdout_color_mt("OpenGL Demo");
		logger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::GetLogger()
	{
		return logger;
	}
}
