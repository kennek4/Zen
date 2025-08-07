#include <zen/core/ZEN_Application.h>
#include <zen/core/ZEN_Window.h>
#include <zen/zen_pch.h>

namespace Zen {
Application::Application() {
    WindowProperties properties = {"Zen Window Test", 1280, 720, true, false};
    m_eventDispatcher.registerListener(0, this);
    m_window = Window::create(properties, &m_eventDispatcher);
};

Application::~Application() {

};

bool Application::onEvent(const SDL_Event &event) {
    if (event.type == SDL_EVENT_QUIT) {
        m_isRunning = false;
        return true;
    };
    return false;
};

void Application::run() {
    ZEN_LOG_INFO("Running Application...");
    while (m_isRunning) {
        // std::cout << "Updating window..." << std::endl;
        m_eventDispatcher.poll();
        m_window.get()->onUpdate();
    };
    ZEN_LOG_INFO("Closing Application...");
};
}; // namespace Zen
