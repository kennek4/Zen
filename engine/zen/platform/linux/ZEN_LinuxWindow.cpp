#include "zen/logger/ZEN_Logger.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_video.h>
#include <cstdint>
#include <zen/core/ZEN_Window.h>
#include <zen/platform/linux/ZEN_LinuxWindow.h>

namespace Zen {

static bool s_SDLInitialized = false;

LinuxWindow::LinuxWindow(const WindowProperties &properties) {
    init(properties);
};

LinuxWindow::~LinuxWindow() { shutdown(); };

// TEMP MUST CHANGE
WindowData &LinuxWindow::getWindowData() { return m_windowData; };

WindowProperties &LinuxWindow::getProperties() { return m_windowProperties; };

static bool resizeEvent(void *windowData, SDL_Event *event) {
    // Handles if the event provided is something we care about or not
    if (!(event->type == SDL_EVENT_WINDOW_RESIZED)) {
        return false;
    };

    // Converts from void* type to the respective type THAT THIS CALLBACK
    // --SHOULD-- be given;
    LinuxWindow *pWinData = reinterpret_cast<LinuxWindow *>(windowData);

    WindowProperties &props = pWinData->getProperties();

    int newWidth, newHeight;
    SDL_GetWindowSize(pWinData->getWindowData().window, &newWidth, &newHeight);

    // Logs the new window width and height
    ZEN_LOG_INFO("Window Width: {}", newWidth);
    ZEN_LOG_INFO("Window Height: {}", newHeight);

    // Assigns the window properties to their new values
    props.width = newWidth;
    props.height = newHeight;

    // Checks to test if the window properties was actually changed by the
    // above assignments to newWidth and newHeight respectively.
    ZEN_LOG_INFO("New WinProp Width: {}", props.width);
    ZEN_LOG_INFO("New WinProp Height: {}", props.height);

    return true;
};

void LinuxWindow::init(const WindowProperties &properties) {
    m_windowProperties.title = properties.title;
    m_windowProperties.width = properties.width;
    m_windowProperties.height = properties.height;

    // TODO: ZEN_LOG
    ZEN_LOG_INFO("Creating new SDL Window: {}, W:{} H: {}",
                 m_windowProperties.title, m_windowProperties.width,
                 m_windowProperties.height);
    if (!s_SDLInitialized) {
        bool success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        if (!success) {
            const char *error = SDL_GetError();
            emitErrorMessage(error);
            ZEN_LOG_ERROR("SDL was not initialized properly: {}", error);
            // std::cout << "SDL Initialization Error: " << SDL_GetError() <<
            // std::endl;
        };

        ZEN_LOG_INFO("SDL Successfully Initialized!");
        s_SDLInitialized = true;
    };

    constexpr SDL_WindowFlags flags =
        SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS |
        SDL_WINDOW_MOUSE_CAPTURE | SDL_WINDOW_RESIZABLE;

    // UNCOMMENT BELOW TO FORCE ERROR
    // SDL_WindowFlags flags;

    m_windowData.window = SDL_CreateWindow(m_windowProperties.title.c_str(),
                                           m_windowProperties.width,
                                           m_windowProperties.height, flags);
    if (m_windowData.window == nullptr) {
        const char *error = SDL_GetError();
        emitErrorMessage(error);
        ZEN_LOG_ERROR("The SDL Window could not be initialized. {}", error);
        // std::cout << "Window Initialization Error: " << SDL_GetError() <<
        // std::endl;
    };

    m_windowData.glContext = SDL_GL_CreateContext(m_windowData.window);
    if (m_windowData.glContext == nullptr) {
        const char *error = SDL_GetError();
        emitErrorMessage(error);
        ZEN_LOG_ERROR("The SDL OpenGL context could not be initialized: {}",
                      error);
        // std::cout << "OpenGL Context Initialization Error: " <<
        // SDL_GetError() << std::endl;
    };

    gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

    setVSync(m_windowProperties.vsync);

    // SET EVENT CALLBACKS HERE
    SDL_AddEventWatch(resizeEvent, this);

    ZEN_LOG_INFO("Window Successfully Initialized!");
};

void LinuxWindow::shutdown() {
    SDL_GL_DestroyContext(m_windowData.glContext);
    SDL_DestroyWindow(m_windowData.window);
    SDL_Quit();
};

void LinuxWindow::onUpdate() {
    SDL_Event event;
    SDL_PollEvent(&event);

    // ZEN_LOG_INFO("Invoking callback...");
    m_eventCallbackFunction(event);

    // ZEN_LOG_INFO("Clearing color buffer...");
    glClearColor(0.7f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(m_windowData.window);
};

uint32_t LinuxWindow::getWidth() { return m_windowProperties.width; };

uint32_t LinuxWindow::getHeight() { return m_windowProperties.height; };

void LinuxWindow::setVSync(bool enabled) {
    if (enabled) {
        SDL_GL_SetSwapInterval(1);
        ZEN_LOG_INFO("VSync On");

    } else {
        SDL_GL_SetSwapInterval(0);
        ZEN_LOG_INFO("VSync Off");
    };
};

bool LinuxWindow::isVSyncEnabled() const { return m_windowProperties.vsync; };

void LinuxWindow::toggleFullscreen() {
    m_windowProperties.fullscreen = !m_windowProperties.fullscreen;
    SDL_SetWindowFullscreen(m_windowData.window, m_windowProperties.fullscreen);
};

void LinuxWindow::setEventCallback(const EventCallbackFunction &callback) {
    m_eventCallbackFunction = callback;
};

// This should ONLY BE CALLED ON THE MAIN THREAD
void LinuxWindow::emitErrorMessage(const char *message) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Zen Error", message,
                             nullptr);
};

}; // namespace Zen
