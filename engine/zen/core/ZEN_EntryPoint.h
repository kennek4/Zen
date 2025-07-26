#pragma once

#include <zen/core/ZEN_Application.h>

#ifdef __ZEN_PLATFORM_LINUX
extern Zen::Application *Zen::CreateApplication();
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Hello, Linux!" << std::endl;
    auto app = Zen::CreateApplication();
    app->run();

    std::cout << "Deleting app..." << std::endl;
    delete app;
};

#endif // __ZEN_PLATFORM_LINUX

#ifdef __ZEN_PLATFORM_WINDOWS
// NOT USED YET
#endif // __ZEN_PLATFORM_LINUX
