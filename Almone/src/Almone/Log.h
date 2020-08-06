#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Almone {
	class ALM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logging macros
#define ALM_CORE_TRACE(...) ::Almone::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ALM_CORE_INFO(...)  ::Almone::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ALM_CORE_WARN(...)  ::Almone::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ALM_CORE_ERROR(...) ::Almone::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ALM_CORE_FATAL(...) ::Almone::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core logging macros
#define ALM_TRACE(...)      ::Almone::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ALM_INFO(...)       ::Almone::Log::GetClientLogger()->info(__VA_ARGS__)
#define ALM_WARN(...)       ::Almone::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ALM_ERROR(...)      ::Almone::Log::GetClientLogger()->error(__VA_ARGS__)
#define ALM_FATAL(...)      ::Almone::Log::GetClientLogger()->fatal(__VA_ARGS__)