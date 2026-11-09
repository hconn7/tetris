#include "layout.h"
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, Cell& c) {
  return out << c.m_x << c.m_y;
}
std::ostream& operator<<(std::ostream& out, Layout& layout) {
  for (int y = 0; y < layout.rows; ++y) {
    for (int x = 0; x < layout.cols; ++x) {
      out << layout.grid[y][x] << " ";
    }
    out << "\n";
  }
  return out;
}

std::vector<Cell> makeCellMatrix(Layout& layout) {
  layout.m_cellMatrix = std::vector<Cell>{};

  for (float y = 0; y < layout.rows; ++y) {
    for (float x = 0; x < layout.cols; ++x) {
      if (y == 0 && x < 1) {
        layout.m_cellMatrix.push_back({x * layout.cellSize, y});
      } else {
        layout.m_cellMatrix.push_back({layout.cellSize * x, layout.cellSize * y});
      }
    }
  }
  std::cout << "render matrix made";
  return layout.m_cellMatrix;
}
std::vector<std::vector<Cell>> Layout::makeGrid() {

  grid = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols));
  for (float y{0}; y < rows; ++y) {
    for (float x{0}; x < cols; ++x) {
      grid[y][x] = Cell{x, y};
    }
  }
  return grid;
}
