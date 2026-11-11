#pragma once

namespace Config {
constexpr float cellSize{40.f}; // 40 x 40
constexpr int gridRows{20};
constexpr int gridCols{10};
constexpr int windowWidth = cellSize * gridCols;
constexpr int windowHeight = cellSize * gridRows;
} // namespace Config
