#include "layout.h"
#include "config.h"
#include "tetrimino.h"
#include <SDL3/SDL_rect.h>
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, Cell& c) {
  return out << c.m_point.m_x << c.m_point.m_y;
}
std::ostream& operator<<(std::ostream& out, Layout& layout) {
  for (int y = 0; y < layout.m_rows; ++y) {
    for (int x = 0; x < layout.m_cols; ++x) {
      out << layout.m_grid[y][x] << " ";
    }
    out << "\n";
  }
  return out;
}

std::vector<Cell> makeCellMatrix(Layout& layout) {
  layout.m_cellMatrix = std::vector<Cell>{};

  for (int y = 0; y < layout.m_rows; ++y) {
    for (int x = 0; x < layout.m_cols; ++x) {
      if (y == 0 && x < 1) {

        layout.m_cellMatrix.push_back(Point{static_cast<int>(layout.m_cellSize) * x, y});
      } else {
        layout.m_cellMatrix.push_back(Point{static_cast<int>(layout.m_cellSize) * x, static_cast<int>(layout.m_cellSize) * y});
      }
    }
  }
  std::cout << "render matrix made";
  return layout.m_cellMatrix;
}
std::vector<std::vector<Cell>> Layout::makeGrid() {
  m_grid = std::vector<std::vector<Cell>>(m_rows, std::vector<Cell>(m_cols));
  for (int y{0}; y < m_rows; ++y) {
    for (int x{0}; x < m_cols; ++x) {
      m_grid[y][x] = Cell{Point{x, y}};
    }
  }
  return m_grid;
}

bool Layout::isItOccupied(std::span<SDL_FRect> allRects) {
  bool isOccupied{false};
  for (const SDL_FRect& rect : allRects) {
    for (Cell& c : m_cellMatrix) {
      if ((rect.y) + Config::cellSize == c.isItOccupied()) {
        isOccupied = true;
      }
    }
  }
  return isOccupied;
}
