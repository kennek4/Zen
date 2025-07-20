#pragma once

#include<base/ZEN_Types.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <format>
#include <memory>

// spdlog wrapper
class ZEN_LoggerManager {
  public: 

    static void init();

    template <typename... Args>
    static void trace(fmt::format_string<Args...> fmt, Args&&... args) {
      SPDLOG_TRACE(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void debug(fmt::format_string<Args...> fmt, Args&&... args) {
      spdlog::debug(fmt, std::forward<Args>(args)...);
      SPDLOG_DEBUG(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void info(fmt::format_string<Args...> fmt, Args&&... args) {
      spdlog::info(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void warn(fmt::format_string<Args...> fmt, Args&&... args) {
      spdlog::warn(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void error(fmt::format_string<Args...> fmt, Args&&... args) {
      spdlog::error(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static void critical(fmt::format_string<Args...> fmt, Args&&... args) {
      spdlog::critical(fmt, std::forward<Args>(args)...);
    }

};