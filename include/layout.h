#include "cell.h"
#include <iostream>
#include <ostream>
#include <vector>

struct Layout {
  Layout() = default;

  std::vector<std::vector<Cell>> makeGrid();

  std::vector<Cell> m_cellMatrix;
  int rows{30};
  int cols{30};
  float cellSize{40};
  std::vector<std::vector<Cell>> grid;

  Cell& operator[](int idx) {
    return grid[idx][idx];
  }
};

std::vector<Cell> makeCellMatrix(Layout& layout);
std::ostream& operator<<(std::ostream& out, Layout& layout);
