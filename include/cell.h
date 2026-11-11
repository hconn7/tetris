
#pragma once

struct Cell {
  Cell() = default;
  Cell(float x, float y) : m_x{x}, m_y{y} {}

  float m_height{100};
  float m_width{100};
  float m_x;
  float m_y;
};
