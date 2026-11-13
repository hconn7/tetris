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
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  I_Tetrimino tetrimino_I{};
  I_Tetrimino tetrimino_I2{};

  Uint64 initialTime = SDL_GetTicks();
  Uint64 accumulator = 0;
  Uint64 INTERVAL_MS = 500;

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
    Uint64 currentTime = SDL_GetTicks();
    Uint64 deltaTime = currentTime - initialTime;
    initialTime = currentTime;
    accumulator += deltaTime;

    while (SDL_PollEvent(&e)) {

      if (e.type == SDL_EVENT_QUIT) {
        sys.isRunning = false;
      } else if (e.key.key == SDLK_D || e.key.key == SDLK_A) {
        tetrimino_I.moveTetriminoOnX(e.key.key);
      }
    }

    while (accumulator >= INTERVAL_MS) {
      tetrimino_I.moveTetriminoOnY(layout);
      accumulator = 0;
    }

    SDL_SetRenderDrawColor(sys.renderer, 0, 0, 0, 255);
    SDL_RenderClear(sys.renderer);

    if (!renderGrid(sys, layout)) {
      sys.isRunning = false;
    }
    if (!renderTetrimino(sys, tetrimino_I)) {
      sys.isRunning = false;
      SDL_Log("Failed to render Tetrimino: %s", SDL_GetError());
    }
    SDL_RenderPresent(sys.renderer);
  }

  destroy(sys);
  return 0;
}
