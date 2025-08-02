#include "zen/core/ZEN_Window.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_video.h>
#include <functional>
#include <memory>
#include <zen/core/ZEN_Application.h>

namespace Zen {
Application::Application() {
    WindowProperties properties = {"Zen Window Test", 1280, 720, true, false};
    m_window = Window::create(properties);
    m_window->setEventCallback(
        std::bind(&Application::onEvent, this, std::placeholders::_1));
};

Application::~Application() {

};

void Application::onEvent(SDL_Event &event) {
    if (event.type == SDL_EVENT_QUIT) {
        m_isRunning = false;
    };
};

void Application::run() {
    ZEN_LOG_INFO("Running Application...");
    while (m_isRunning) {
        // std::cout << "Updating window..." << std::endl;
        m_window.get()->onUpdate();
    };
    ZEN_LOG_INFO("Closing Application...");
};
}; // namespace Zen
