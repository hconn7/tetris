#include "system.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>

void destroy(SystemState& sys) {
  SDL_DestroyRenderer(sys.renderer);
  sys.renderer = nullptr;

  SDL_DestroyWindow(sys.window);
  sys.window = nullptr;

  sys.isRunning = false;
}

bool init(SystemState& sys) {
  bool success = true;
  if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
    SDL_Log("Issue with SDL Sub system %s", SDL_GetError());
    success = false;
  }
  if (!SDL_CreateWindowAndRenderer("Tetris", 680, 900, SDL_WINDOW_RESIZABLE, &sys.window, &sys.renderer)) {
    SDL_Log("Issue with SDL Sub system %s", SDL_GetError());
    success = false;
  }
  return success;
}

bool renderGrid(SystemState& sys, Layout& l) {
  SDL_SetRenderDrawColor(sys.renderer, 255, 255, 255, 255);
  std::cout << "Draw Color set\n";
  for (float i = 0; i < l.m_cellMatrix.size(); i++) {
    float x1 = l.m_cellMatrix[i].m_x;
    float y1 = l.m_cellMatrix[i].m_y;
    float x2 = l.m_cellMatrix[i].m_x;
    float y2 = l.m_cellMatrix[i].m_y;

    SDL_Log("Drawing Cell starting at X: %f Y: %f", x1, y1);

    SDL_RenderLine(sys.renderer, x1, y1, x2, y2 + l.cellSize);
    SDL_RenderLine(sys.renderer, x1, y1, x2 + l.cellSize, y2);
    SDL_RenderLine(sys.renderer, x1, y1 + l.cellSize, x2 + l.cellSize, y2 + l.cellSize);
    SDL_RenderLine(sys.renderer, x1 + l.cellSize, y1 + l.cellSize, x2 + l.cellSize, y2);
  }

  return true;
}
