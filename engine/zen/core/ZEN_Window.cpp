#include <SDL3/SDL_init.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <cstdint>
#include <zen.h>
#include <zen/core/ZEN_Window.h>

Zen::Window::Window() { init(); };

Zen::Window::Window(WindowProperties properties) {
  m_properties = properties;
  init();
};

Zen::Window::~Window() { shutdown(); };

bool Zen::Window::init() {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    // TODO: ZEN_Logger [ERROR]
    // Call SDL_Error() to get the error
    return false;
  };

  uint32_t winFlags = 0;
  winFlags |= SDL_WINDOW_OPENGL;
  winFlags |= SDL_WINDOW_INPUT_FOCUS;
  winFlags |= SDL_WINDOW_MOUSE_FOCUS;
  winFlags |= SDL_WINDOW_MOUSE_CAPTURE;

  // Check window creation flags
  if ((m_properties.flags & FLAG_WINDOW_FULLSCREEN) > 0) {
    m_properties.fullscreen = true;
    winFlags |= SDL_WINDOW_FULLSCREEN;
  };

  if ((m_properties.flags & FLAG_WINDOW_UNDECORATED) > 0) {
    winFlags |= SDL_WINDOW_BORDERLESS;
  };

  if ((m_properties.flags & FLAG_WINDOW_MINIMIZED) > 0) {
    winFlags |= SDL_WINDOW_MINIMIZED;
  };

  if ((m_properties.flags & FLAG_WINDOW_MAXIMIZED) > 0) {
    winFlags |= SDL_WINDOW_MAXIMIZED;
  };

  m_sdlData.window =
      SDL_CreateWindow(m_properties.title, m_properties.screen.width,
                       m_properties.screen.height, winFlags);
  if (m_sdlData.window == nullptr) {
    // TODO: ZEN_Logger [ERROR]
    // Call SDL_Error() to get the error
    return false;
  };

  m_sdlData.glContext = SDL_GL_CreateContext(m_sdlData.window);
  if (m_sdlData.glContext == nullptr) {
    // TODO: ZEN_Logger [ERROR]
    // Call SDL_Error() to get the error
    return false;
  };

  // Load OpenGL Functions
  gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

  // TODO: ZEN_Logger [INFO]
  // gladLoadGL returns an int representing the GLAD major and minor version
  // GLAD_VERSION_MAJOR and GLAD_VERSION_MINOR respectively

  m_properties.ready = true;

  SDL_DisplayID currMonitor = SDL_GetDisplayForWindow(m_sdlData.window);
  const SDL_DisplayMode *displayMode = SDL_GetCurrentDisplayMode(currMonitor);

  m_properties.monitor.width = displayMode->w;
  m_properties.monitor.height = displayMode->h;

  if (m_properties.flags & FLAG_WINDOW_VSYNC) {
    SDL_GL_SetSwapInterval(1);
    // TODO: ZEN_Logger [INFO]
    // VSync turned on
  } else {
    SDL_GL_SetSwapInterval(0);
    // TODO: ZEN_Logger [INFO]
    // VSync turned off
  };

  // TODO: ZEN_Logger [INFO]
  // SDL successfully initialized

  return true;
};

bool Zen::Window::shutdown() {
  SDL_DestroyCursor(m_sdlData.cursor);
  SDL_GL_DestroyContext(m_sdlData.glContext);
  SDL_DestroyWindow(m_sdlData.window);
  SDL_Quit();

  return true;
};

// SDL Window
void Zen::Window::setWindowTitle(const char *newTitle) {
  m_properties.title = newTitle;
};

void Zen::Window::maximize() {
  SDL_MaximizeWindow(m_sdlData.window);
  if ((m_properties.flags & FLAG_WINDOW_MAXIMIZED) == 0) {
    m_properties.flags |= FLAG_WINDOW_MAXIMIZED;
  };
};

void Zen::Window::minimize() {
  SDL_MinimizeWindow(m_sdlData.window);
  if ((m_properties.flags & FLAG_WINDOW_MINIMIZED) == 0) {
    m_properties.flags |= FLAG_WINDOW_MINIMIZED;
  };
};

void Zen::Window::toggleFullscreen() {
  const SDL_WindowID monitor = SDL_GetWindowID(m_sdlData.window);
  int monitorCount = 0;
  SDL_DisplayID *monitors = SDL_GetDisplays(&monitorCount);

  if ((monitorCount > 0) && monitor <= monitorCount) {
    if ((m_properties.flags & FLAG_WINDOW_FULLSCREEN) > 0) {
      SDL_SetWindowFullscreen(m_sdlData.window, 0);
      m_properties.flags &= ~FLAG_WINDOW_FULLSCREEN;
      m_properties.fullscreen = false;
    } else {
      SDL_SetWindowFullscreen(m_sdlData.window, SDL_WINDOW_FULLSCREEN);
      m_properties.flags |= FLAG_WINDOW_FULLSCREEN;
      m_properties.fullscreen = true;
    };
  };

  SDL_free(monitors);
};

// SDL Cursor
void Zen::Window::showCursor() { SDL_ShowCursor(); };

void Zen::Window::hideCursor() { SDL_HideCursor(); };

void Zen::Window::enableCursor() {
  SDL_WarpMouseInWindow(m_sdlData.window, m_properties.screen.width / 2.0f,
                        m_properties.screen.height / 2.0f);
  SDL_SetWindowRelativeMouseMode(m_sdlData.window, false);
};

void Zen::Window::disableCursor() {
  SDL_SetWindowRelativeMouseMode(m_sdlData.window, true);
};

// SDL Timer
double Zen::Window::getTime() {
  double time = (double)SDL_GetTicks();
  return time / 1000;
};
