#pragma once

#include <spdlog/spdlog.h>
 
  //spdlog wrapper
  class ZEN_LoggerManager {
      public:

        static void init();

        template <typename... Args>
        static void trace(fmt::format_string<Args...> fmt, Args&&... args) {
            spdlog::trace(fmt, std::forward<Args>(args)...);
            //SPDLOG_TRACE(std::forward<Args>(args)...);
        }
  
        template <typename... Args>
        static void debug(fmt::format_string<Args...> fmt, Args&&... args) {
              spdlog::debug(fmt, std::forward<Args>(args)...);
            //SPDLOG_DEBUG(std::forward<Args>(args)...);
        }
  
        template <typename... Args>
        static void info(fmt::format_string<Args...> fmt, Args&&... args) {
              spdlog::info(fmt, std::forward<Args>(args)...);
            //SPDLOG_INFO(std::forward<Args>(args)...);
        }
  
        template <typename... Args>
        static void warn(fmt::format_string<Args...> fmt, Args&&... args) {
              spdlog::warn(fmt, std::forward<Args>(args)...);
            //SPDLOG_WARN(std::forward<Args>(args)...);
        }
  
        template <typename... Args>
        static void error(fmt::format_string<Args...> fmt, Args&&... args) {
              spdlog::error(fmt, std::forward<Args>(args)...);
            //SPDLOG_ERROR(std::forward<Args>(args)...);
        }
  
        template <typename... Args>
        static void critical(fmt::format_string<Args...> fmt, Args&&... args) {
              spdlog::critical(fmt, std::forward<Args>(args)...);
            //SPDLOG_CRITICAL(std::forward<Args>(args)...);
      }
  };

#define ZEN_LOG_TRACE(...) ::ZEN_LoggerManager::trace(__VA_ARGS__) //spdlog::trace(fmt)
#define ZEN_LOG_DEBUG(...) ::ZEN_LoggerManager::debug(__VA_ARGS__) //spdlog::debug(fmt)
#define ZEN_LOG_INFO(...) ::ZEN_LoggerManager::info(__VA_ARGS__) //spdlog::info(fmt)
#define ZEN_LOG_WARN(...) ::ZEN_LoggerManager::warn(__VA_ARGS__) //spdlog::warn(fmt)
#define ZEN_LOG_ERROR(...) ::ZEN_LoggerManager::error(__VA_ARGS__) //spdlog::error(__VA_ARGS__)
#define ZEN_LOG_CRITICAL(...) ::ZEN_LoggerManager::critical(__VA_ARGS__) //spdlog::critical(fmt)
