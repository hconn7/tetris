#include "tetrimino.h"
#include "config.h"
#include "layout.h"
#include <SDL3/SDL_rect.h>
#include <iostream>

void Tetrimino::moveTetriminoOnX(SDL_Keycode k) {
  switch (k) {
  case SDLK_D: {
    for (const auto& s : m_allRects) {
      if (s.x + Config::cellSize >= Config::windowWidth) {
        return;
      }
    }
    for (auto& s : m_allRects) {
      s.x += Config::cellSize;
    }
    break;
  }
  case SDLK_A: {
    for (const auto& s : m_allRects) {
      if (s.x <= 0) {
        return;
      }
    }
    for (auto& s : m_allRects) {
      s.x -= Config::cellSize;
    }
    break;
  }
  default:
    break;
  }
}
void Tetrimino::moveTetriminoOnY(Layout& l) {
  for (SDL_FRect& s : m_allRects) {
    if (s.y + Config::cellSize >= Config::windowHeight || l.isItOccupied(m_allRects)) {
      return;
    } else {
      std::cout << "Moveing!\n";
      s.y += Config::cellSize;
    }
  }
}
