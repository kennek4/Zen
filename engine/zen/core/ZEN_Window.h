#pragma once

#include <cstdint>
#include <zen/ZEN_Types.h>
#include <zen/core/ZEN_SDL.h>

namespace Zen {
typedef struct {
  const char *title;
  bool ready;
  bool fullscreen;
  Zen::Size screen;
  Zen::Size monitor;
  uint32_t flags;
} WindowProperties;

typedef enum {
  FLAG_WINDOW_VSYNC = 0x00000040,      // Set to try enabling V-Sync on GPU
  FLAG_WINDOW_FULLSCREEN = 0x00000002, // Set to run program in fullscreen
  FLAG_WINDOW_RESIZABLE = 0x00000004,  // Set to allow resizable window
  FLAG_WINDOW_UNDECORATED =
      0x00000008, // Set to disable window decoration (frame and buttons)
  FLAG_WINDOW_HIDDEN = 0x00000080,    // Set to hide window
  FLAG_WINDOW_MINIMIZED = 0x00000200, // Set to minimize window (iconify)
  FLAG_WINDOW_MAXIMIZED =
      0x00000400, // Set to maximize window (expanded to monitor)
  FLAG_WINDOW_ALWAYS_RUN =
      0x00000100, // Set to allow windows running while minimized
  FLAG_WINDOW_TRANSPARENT = 0x00000010, // Set to allow transparent framebuffer
  FLAG_WINDOW_HIGHDPI = 0x00002000,     // Set to support HighDPI
  FLAG_WINDOW_MOUSE_PASSTHROUGH =
      0x00004000, // Set to support mouse passthrough, only supported when
                  // FLAG_WINDOW_UNDECORATED
  FLAG_BORDERLESS_WINDOWED_MODE =
      0x00008000, // Set to run program in borderless windowed mode
} ZEN_WindowFlags;

class Window {
public:
  Window();
  Window(WindowProperties properties);
  ~Window();

  bool init();
  bool shutdown();

  // SDL Window
  void setWindowTitle(const char *newTitle);
  void maximize();
  void minimize();
  void toggleFullscreen();
  void swapScreenBuffer();

  // SDL Cursor
  void showCursor();
  void hideCursor();
  void enableCursor();
  void disableCursor();

  // SDL Timer
  double getTime();

private:
  WindowProperties m_properties;
  SDLData m_sdlData;
};
}; // namespace Zen
