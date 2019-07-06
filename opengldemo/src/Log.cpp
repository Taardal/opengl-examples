#include "pch.h"
#include "Log.h"

namespace Demo
{
	void Log::SetLevel(LogLevel logLevel)
	{
		spdlog::set_level(GetSpdLogLevel(logLevel));
	}

	std::string Log::GetPrefixedMessage(const std::string& message, const std::string& tag, const std::string& functionName, int lineNumber)
	{
		std::stringstream ss;
		ss << "[" << tag << ":" << functionName << ":" << lineNumber << "] - " << message;
		return ss.str();
	}

	spdlog::level::level_enum Log::GetSpdLogLevel(LogLevel logLevel)
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