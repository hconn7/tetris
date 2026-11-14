#include "tetrimino.h"
#include "cell.h"
#include "config.h"
#include "layout.h"
#include "random.h"
#include "tetrimino_I.h"
#include <SDL3/SDL_rect.h>
#include <iostream>
#include <memory>

void Tetrimino::moveTetriminoOnX(SDL_Keycode k) {
  switch (k) {
  case SDLK_D: {
    for (const auto& s : m_allRects) {
      if (s.x + Config::cellSize >= Config::windowWidth) {
        return;
      }
    }
    for (auto& s : m_allRects) {
      s.x += Config::cellSize - 20;
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
      s.x -= Config::cellSize - 20;
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
      s.y += Config::cellSize;
    }
  }
}

std::vector<Point> Tetrimino::getPoint() {
  std::vector<Point> points{};
  for (SDL_FRect& s : m_allRects) {
    points.emplace_back(s.x, s.y);
  }
  return points;
}

std::unique_ptr<Tetrimino> getRandomTetrimino() {
  //  int randomNum{Random::get(0, Tetrimino::MAX_TETRIMINOS - 1)};
  // auto Type = static_cast<Tetrimino::Type>(0);
  return std::make_unique<I_Tetrimino>();
}

std::vector<std::unique_ptr<Tetrimino>> makeAllTetriminos(int count) {
  std::vector<std::unique_ptr<Tetrimino>> allTetriminos{};
  for (int i = 0; i < count; i++) {
    std::unique_ptr<Tetrimino> t = getRandomTetrimino();
    allTetriminos.push_back(std::move(t));
  }
  return allTetriminos;
}
