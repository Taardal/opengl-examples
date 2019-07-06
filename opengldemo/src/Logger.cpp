#include "pch.h"
#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Demo
{
	Logger::Logger(const std::string& name)
		: logger(spdlog::stdout_color_mt(name))
	{
		SetLevel(LogLevel::Trace);
	}

	Logger::~Logger()
	{
	}

	void Logger::SetLevel(const LogLevel& logLevel)
	{
		logger->set_level(GetSpdLogLevel(logLevel));
	}

	void Logger::SetGlobalLevel(const LogLevel& logLevel)
	{
		spdlog::set_level(GetSpdLogLevel(logLevel));
	}

	spdlog::level::level_enum Logger::GetSpdLogLevel(const LogLevel& logLevel)
	{
		switch (logLevel)
		{
		case LogLevel::Critical:
			return spdlog::level::critical;
		case LogLevel::Error:
			return spdlog::level::err;
		case LogLevel::Warn:
			return spdlog::level::warn;
		case LogLevel::Info:
			return spdlog::level::info;
		case LogLevel::Debug:
			return spdlog::level::debug;
		default:
			return spdlog::level::trace;
		}
	}
}