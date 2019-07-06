#pragma once

#include "spdlog/spdlog.h"

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

	class Logger
	{
	private:
		std::shared_ptr<spdlog::logger> logger;

	public:
		Logger(const std::string& name);
		~Logger();

		void SetLevel(const LogLevel& logLevel);
		static void SetGlobalLevel(const LogLevel& logLevel);

		template<typename... T>
		void Trace(const std::string& message, const T& ... args)
		{
			logger->trace(message.c_str(), args...);
		}

		template<typename... T>
		void Debug(const std::string& message, const T& ... args)
		{
			logger->debug(message.c_str(), args...);
		}

		template<typename... T>
		void Info(const std::string& message, const T&... args)
		{
			logger->info(message.c_str(), args...);
		}

		template<typename... T>
		void Warn(const std::string& message, const T& ... args)
		{
			logger->warn(message.c_str(), args...);
		}

		template<typename... T>
		void Error(const std::string& message, const T& ... args)
		{
			logger->error(message.c_str(), args...);
		}

		template<typename... T>
		void Critical(const std::string& message, const T& ... args)
		{
			logger->critical(message.c_str(), args...);
		}

		template<typename... T>
		static void GlobalTrace(const std::string& message, const T& ... args)
		{
			spdlog::trace(message.c_str(), args...);
		}

		template<typename... T>
		static void GlobalDebug(const std::string& message, const T& ... args)
		{
			spdlog::debug(message.c_str(), args...);
		}

		template<typename... T>
		static void GlobalInfo(const std::string& message, const T& ... args)
		{
			spdlog::info(message.c_str(), args...);
		}

		template<typename... T>
		static void GlobalWarn(const std::string& message, const T& ... args)
		{
			spdlog::warn(message.c_str(), args...);
		}

		template<typename... T>
		static void GlobalError(const std::string& message, const T& ... args)
		{
			spdlog::error(message.c_str(), args...);
		}

		template<typename... T>
		static void GlobalCritical(const std::string& message, const T& ... args)
		{
			spdlog::critical(message.c_str(), args...);
		}

	private:
		static spdlog::level::level_enum GetSpdLogLevel(const LogLevel& logLevel);
	};
}