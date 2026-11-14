
#pragma once

#include "config.h"

struct Point {
public:
  int m_x;
  int m_y;

  bool m_cellIsOccupied{false};

  Point getCellXY() noexcept { return Point{m_x / 40, m_y / 40}; }
  int getCellY() noexcept { return m_y / 40; }
  int getCellX() noexcept { return m_x / 40; }
  bool operator==(Point other) { return m_x == other.m_x && m_y == other.m_y; }
};

struct Cell {
public:
  Cell() = default;
  Cell(Point p) : m_point{p.m_x, p.m_y} {}

  void isOccupied(Point p) noexcept {
    p.m_cellIsOccupied = true;
    return;
  }
  bool isItOccupied() { return m_point.m_cellIsOccupied; }

  float m_height{100};
  float m_width{100};
  Point m_point;
};
