#pragma once

#include "spdlog/spdlog.h"

#include "Core.h"

#define LOG_T(tag, message, ...) Demo::Log::Trace(Demo::Log::GetPrefixedMessage(message, tag, __func__, __LINE__), __VA_ARGS__)
#define LOG_D(tag, message, ...) Demo::Log::Debug(Demo::Log::GetPrefixedMessage(message, tag, __func__, __LINE__), __VA_ARGS__)
#define LOG_I(tag, message, ...) Demo::Log::Info(Demo::Log::GetPrefixedMessage(message, tag, __func__, __LINE__), __VA_ARGS__)
#define LOG_W(tag, message, ...) Demo::Log::Warn(Demo::Log::GetPrefixedMessage(message, tag, __func__, __LINE__), __VA_ARGS__)
#define LOG_E(tag, message, ...) Demo::Log::Error(Demo::Log::GetPrefixedMessage(message, tag, __func__, __LINE__), __VA_ARGS__)
#define LOG_C(tag, message, ...) Demo::Log::Critical(Demo::Log::GetPrefixedMessage(message, tag, __func__, __LINE__), __VA_ARGS__)

namespace Demo
{
	enum class LogLevel
	{
		Trace,
		Debug,
		Info,
		Warn,
		Error,
		Critical
	};

	class Log
	{
	public:
		static void SetLevel(LogLevel logLevel);
		static std::string GetPrefixedMessage(const std::string& message, const std::string& tag, const std::string& functionName, int lineNumber);

		template<typename... T>
		static void Trace(const std::string& message, const T& ... args)
		{
			spdlog::trace(message.c_str(), args...);
		}

		template<typename... T>
		static void Debug(const std::string& message, const T& ... args)
		{
			spdlog::debug(message.c_str(), args...);
		}

		template<typename... T>
		static void Info(const std::string& message, const T& ... args)
		{
			spdlog::info(message.c_str(), args...);
		}

		template<typename... T>
		static void lWarn(const std::string& message, const T& ... args)
		{
			spdlog::warn(message.c_str(), args...);
		}

		template<typename... T>
		static void Error(const std::string& message, const T& ... args)
		{
			spdlog::error(message.c_str(), args...);
		}

		template<typename... T>
		static void Critical(const std::string& message, const T& ... args)
		{
			spdlog::critical(message.c_str(), args...);
		}

	private:
		Log() = default;
		~Log() = default;

		static spdlog::level::level_enum GetSpdLogLevel(LogLevel logLevel);
	};
}