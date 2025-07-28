#include <zen/logger/ZEN_Logger.h>
//
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Zen {
void Logger::init() {
    auto console = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");

    auto logger = std::make_shared<spdlog::logger>("ZEN_Logger", console);
    logger->set_level(spdlog::level::trace);
    spdlog::set_default_logger(logger);
}
}; // namespace Zen
