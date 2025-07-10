#include "zen/2d/ZEN_GameObject2D.h"
#include "zen/2d/ZEN_Sprite.h"
#include "zen/2d/ZEN_Transform2D.h"
#include "zen/resource/ZEN_ResourceManager.h"
#include <SDL3/SDL_events.h>
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

  ZEN_ResourceManager::getInstance()
      .loadShader("./data/basic.vert", "./data/basic/frag")
      ->setInt("image", 0, true);

  ZEN_ResourceManager::getInstance()
      .loadShader("./data/basic.vert", "./data/basic/frag")
      ->setMatrix4("projection",
                   glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f), true);

  m_gameManger->addGameObject2D(
      "Snoopy", ZEN_ResourceManager::getInstance().loadAlphaTexture(
                    "./data/snoops.png", "SnoopyTexture", true));
};

void ZEN_Engine::startGame() {
  SDL_Window *mainWindow = m_windowManager->getWindow();
  if (mainWindow == NULL) {
    std::cout << "Window could not be retrieved" << std::endl;
    return;
  };

  bool done = false;

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
    m_renderer->renderGameObject(m_gameManger->getGameObject("Snoopy"));

    glClearColor(0.25, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(mainWindow);
  };
};
