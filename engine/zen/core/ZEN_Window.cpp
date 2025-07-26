#include "zen/platform/linux/ZEN_LinuxWindow.h"
#include <iostream>
#include <memory>
#include <zen/core/ZEN_Window.h>

namespace Zen {

std::unique_ptr<Window>
Window::create(const Zen::WindowProperties &properties) {
#ifdef __ZEN_PLATFORM_LINUX
    std::cout << "Creating a Linux Window..." << std::endl;
    return std::make_unique<LinuxWindow>(properties);
#endif              // __ZEN_PLATFORM_LINUX
#ifdef __ZEN_PLATFORM_WINDOWS
    return nullptr; // NOT SUPPORTED
#endif              // __ZEN_PLATFORM_WINDOWS
    // Unsupported OS
    return nullptr;
};

}; // namespace Zen
