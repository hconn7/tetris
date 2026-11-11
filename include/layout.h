
#pragma once
#include "cell.h"
#include "config.h"
#include <iostream>
#include <ostream>
#include <vector>

struct Layout {
  Layout() = default;

  std::vector<std::vector<Cell>> makeGrid();

  float getCellSize();

  std::vector<Cell> m_cellMatrix;
  int rows{Config::gridRows};
  int cols{Config::gridCols};
  float cellSize{(Config::cellSize)};
  std::vector<std::vector<Cell>> grid;

  Cell& operator[](int idx) {
    return grid[idx][idx];
  }
};

std::vector<Cell> makeCellMatrix(Layout& layout);
std::ostream& operator<<(std::ostream& out, Layout& layout);
