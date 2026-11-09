#include "layout.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct SystemState {

  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};
  bool isRunning{};
};
void destroy(SystemState& sys);
bool init(SystemState& sys);
bool renderGrid(SystemState& sys, Layout& l);
