
#pragma once

#include "config.h"

struct Point {
  int m_x;
  int m_y;
};

struct Cell {
  Cell() = default;
  Cell(Point p) : m_point{p.m_x, p.m_y} {}

  inline Point getCellXY() noexcept { return Point{m_point.m_x % 40, m_point.m_y % 40}; }

  float m_height{100};
  float m_width{100};
  Point m_point;
  bool m_cellIsOccupied{false};
};
