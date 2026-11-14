#include "cell.h"
#include "system.h"
#include "tetrimino.h"
#include "tetrimino_I.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <memory>
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {

  Uint64 initialTime = SDL_GetTicks();
  Uint64 accumulator = 0;
  Uint64 INTERVAL_MS = 500;

  std::vector<std::unique_ptr<Tetrimino>> allTetriminos{makeAllTetriminos(10)};
  std::vector<std::unique_ptr<Tetrimino>> allTetriminosOnGrid{};

  int tetriminoPtr{0};

  Layout layout{};
  layout.m_grid = layout.makeGrid();
  makeCellMatrix(layout);

  SystemState sys{0};
  sys.isRunning = true;

  if (!init(sys)) {
    destroy(sys);
  }
  SDL_Event e;
  SDL_zero(e);

  while (sys.isRunning) {

    std::vector<Point> points{allTetriminos[tetriminoPtr]->getPoint()};
    Point point{};

    for (auto& p : points) {
      point = p.getCellXY();
    }
    Uint64 currentTime = SDL_GetTicks();
    Uint64 deltaTime = currentTime - initialTime;
    initialTime = currentTime;
    accumulator += deltaTime;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        sys.isRunning = false;
      } else if (e.key.key == SDLK_D || e.key.key == SDLK_A) {
        allTetriminos[tetriminoPtr]->moveTetriminoOnX(e.key.key);
      }
    }

    while (accumulator >= INTERVAL_MS) {
      allTetriminos[tetriminoPtr]->moveTetriminoOnY(layout);
      accumulator = 0;
      points = allTetriminos[tetriminoPtr]->getPoint();
      for (auto& p : points) {
        if (p.getCellXY() == point) {
          int y = p.getCellY();
          int x = p.getCellX();
          std::cout << "PRINTING Y: " << y << "Printing X: " << '\n';
          Cell cell{layout.m_grid[y][x]};
          cell.isOccupied(cell.m_point);

          std::cout << "Printing Cell Y: " << cell.m_point.m_y << "X: " << cell.m_point.m_x << '\n';

          allTetriminosOnGrid.push_back(std::move(allTetriminos[tetriminoPtr]));
          tetriminoPtr++;
        }
      }
    }

    SDL_SetRenderDrawColor(sys.renderer, 0, 0, 0, 255);
    SDL_RenderClear(sys.renderer);

    if (!renderGrid(sys, layout)) {
      sys.isRunning = false;
    }
    if (!renderTetriminosOnGrid(sys, allTetriminosOnGrid)) {
      sys.isRunning = false;
      SDL_Log("Failed to render Tetrimino: %s", SDL_GetError());
    }
    if (!renderTetrimino(sys, *allTetriminos[tetriminoPtr])) {
      sys.isRunning = false;
      SDL_Log("Failed to render Tetrimino: %s", SDL_GetError());
    }
    SDL_RenderPresent(sys.renderer);
  }

  destroy(sys);
  return 0;
}
