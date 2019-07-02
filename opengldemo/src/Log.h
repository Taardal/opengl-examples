#pragma once

#include "spdlog/spdlog.h"

#define LOG_TRACE(...) Demo::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) Demo::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) Demo::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Demo::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) Demo::Log::GetLogger()->fatal(__VA_ARGS__)

namespace Demo
{
	class Log
	{
	private:
		static std::shared_ptr<spdlog::logger> logger;

	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetLogger();

	private:
		Log();
	};
}