#pragma once

class ZEN_Renderer {
public:
  ZEN_Renderer() = default;
  ~ZEN_Renderer();
  virtual void init() = 0;
  virtual void stop() = 0;
  
};
