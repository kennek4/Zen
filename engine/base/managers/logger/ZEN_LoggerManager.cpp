#include <iostream>
#include <base/managers/logger/ZEN_LoggerManager.h>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

void ZEN_LoggerManager::init() {
  auto console = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  console->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^%l%$]  %v");

  auto logger = std::make_shared<spdlog::logger>("ZEN_Logger", console);
  logger->set_level(spdlog::level::trace);
  spdlog::set_default_logger(logger);
}
