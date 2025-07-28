#pragma once

#include "ZEN_Core.h"
#include <zen/core/ZEN_Application.h>

#ifdef __ZEN_PLATFORM_LINUX
extern Zen::Application *Zen::CreateApplication();

int main(int argc, char *argv[]) {
    Zen::Logger::init();
    ZEN_LOG_INFO("Hello, Linux!");
    auto app = Zen::CreateApplication();
    app->run();

    ZEN_LOG_INFO("Deleting app...");
    delete app;
};

#endif // __ZEN_PLATFORM_LINUX

#ifdef __ZEN_PLATFORM_WINDOWS
// NOT USED YET
#endif // __ZEN_PLATFORM_LINUX
