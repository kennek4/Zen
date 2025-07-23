#include "zen/2d/ZEN_GameObject2D.h"
#include "zen/2d/ZEN_Sprite.h"
#include "zen/2d/ZEN_Transform2D.h"
#include "zen/resource/ZEN_ResourceManager.h"
#include "zen/textures/ZEN_Texture2D.h"
#include <GL/gl.h>
#include <GLES3/gl3.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>
#include <glm/ext/vector_float2.hpp>
#include <iostream>
#include <memory>
#include <zen/ZEN_Engine.h>

ZEN_Engine::ZEN_Engine(ZEN_Window_MetaData *winMetaData) {
  m_gameManger = std::make_unique<ZEN_GameManager>();
  m_windowManager = std::make_unique<ZEN_WindowManager>(winMetaData);
  m_renderer = std::make_unique<ZEN_Renderer2D>();
  init();
};

ZEN_Engine::~ZEN_Engine() {

};

void ZEN_Engine::init() {
  m_renderer->initOpenGL();
  m_renderer->setShader(ZEN_ResourceManager::getInstance().loadShader(
      "./data/basic.vert", "./data/basic.frag"));

  m_renderer->getShader()->setInt("image", 0);
  m_renderer->getShader()->setMatrix4(
      "projection", glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f));

  std::shared_ptr<ZEN_Texture2D> texture =
      ZEN_ResourceManager::getInstance().loadAlphaTexture(
          "./data/redbaron.png", "SnoopyTexture", true);

  m_gameManger->addGameObject2D("Snoopy", texture);
  std::cout << m_gameManger->getGameObject("Snoopy")->texture->getId()
            << std::endl;
};

void ZEN_Engine::startGame() {
  SDL_Window *mainWindow = SDL_GL_GetCurrentWindow();
  if (mainWindow == NULL) {
    std::cout << "Window could not be retrieved" << std::endl;
    return;
  };

  bool done = false;

  glUseProgram(0);

  while (!done) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      };
    };

    // Process input

    // Update game

    // Render
    glClearColor(0.25, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    m_renderer->renderGameObject(m_gameManger->getGameObject("Snoopy"));
    SDL_GL_SwapWindow(mainWindow);
  };
};
