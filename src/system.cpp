#include "system.h"
#include "config.h"
#include "tetrimino.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <memory>

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
  if (!SDL_CreateWindowAndRenderer("Tetris", Config::windowWidth, Config::windowHeight, 0, &sys.window, &sys.renderer)) {
    SDL_Log("Issue with SDL Sub system %s", SDL_GetError());
    success = false;
  }
  return success;
}
// Rendering
bool renderTetrimino(SystemState& sys, const Tetrimino& t) {
  if (!SDL_SetRenderDrawColor(sys.renderer, 0, 239, 255, 255)) {
    SDL_Log("Failed to set render Draw Color for Tetrimino: ");
    return false;
  }
  for (const SDL_FRect& r : t.m_allRects) {
    if (!SDL_RenderFillRect(sys.renderer, &r)) {
      SDL_Log("Failed to set render Draw Color for Tetrimino: ");
      return false;
    }
  }
  return true;
}

bool renderTetriminosOnGrid(SystemState& sys, const std::vector<std::unique_ptr<Tetrimino>>& arr) {
  if (!SDL_SetRenderDrawColor(sys.renderer, 0, 239, 255, 255)) {
    SDL_Log("Failed to set render Draw Color for Tetrimino: ");
    return false;
  }
  for (const auto& t : arr) {
    for (const SDL_FRect r : t->m_allRects)
      if (!SDL_RenderFillRect(sys.renderer, &r)) {
        SDL_Log("Failed to set render Draw Color for Tetrimino: ");
        return false;
        std::cout << "rendering square at: " << r.x << "and" << r.y << '\n';
      }
  }
  return true;
}

bool renderGrid(SystemState& sys, Layout& l) {
  SDL_SetRenderDrawColor(sys.renderer, 255, 255, 255, 255);
  for (float i = 0; i < l.m_cellMatrix.size(); i++) {
    float x1 = l.m_cellMatrix[i].m_point.m_x;
    float y1 = l.m_cellMatrix[i].m_point.m_y;
    float x2 = l.m_cellMatrix[i].m_point.m_x;
    float y2 = l.m_cellMatrix[i].m_point.m_y;

    // SDL_Log("Drawing Cell starting at X: %f Y: %f", x1, y1);

    SDL_RenderLine(sys.renderer, x1, y1, x2, y2 + l.m_cellSize);
    SDL_RenderLine(sys.renderer, x1, y1, x2 + l.m_cellSize, y2);
    SDL_RenderLine(sys.renderer, x1, y1 + l.m_cellSize, x2 + l.m_cellSize, y2 + l.m_cellSize);
    SDL_RenderLine(sys.renderer, x1 + l.m_cellSize, y1 + l.m_cellSize, x2 + l.m_cellSize, y2);
  }

  return true;
}
