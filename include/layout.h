
#pragma once

#include "cell.h"
#include "config.h"
#include "tetrimino.h"
#include <SDL3/SDL_rect.h>
#include <iostream>
#include <ostream>
#include <span>
#include <vector>

struct Layout {
  Layout() = default;

  std::vector<std::vector<Cell>> makeGrid();

  float getCellSize();
  bool isItOccupied(std::span<SDL_FRect>);

  std::vector<Cell> m_cellMatrix;
  int m_rows{Config::gridRows};
  int m_cols{Config::gridCols};
  float m_cellSize{(Config::cellSize)};
  std::vector<std::vector<Cell>> m_grid;

  Cell& operator[](int idx) {
    return m_grid[idx][idx];
  }
};

std::vector<Cell> makeCellMatrix(Layout& layout);
std::ostream& operator<<(std::ostream& out, Layout& layout);
