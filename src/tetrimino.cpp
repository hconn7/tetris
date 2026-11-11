#include "tetrimino.h"
#include "config.h"
#include <SDL3/SDL_rect.h>
void Tetrimino::moveTetriminoOnX(SDL_Keycode k) {
  switch (k) {
  case SDLK_D:
    for (SDL_FRect& s : m_allRects) {
      s.x += Config::cellSize - 20;
    }
    break;
  case SDLK_A:
    for (SDL_FRect& s : m_allRects) {
      s.x -= Config::cellSize - 20;
    }

    break;

  default:
    break;
  }
}
