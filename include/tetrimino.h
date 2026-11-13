
#pragma once

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_rect.h>
#include <vector>

struct Layout;
class Tetrimino {
public:
  std::vector<SDL_FRect> m_allRects;
  enum Type {
    TETRIMINO_I,
    TETRIMINO_O,
    TETRIMINO_T,
    TETRIMINO_J,
    TETRIMINO_K,
    TETRIMINO_S,
    TETRIMINO_Z,
    MAX_TETRIMINOS,
  }; // End Enum

  explicit Tetrimino(Type) {}

  virtual ~Tetrimino() = default;

  void moveTetriminoOnX(SDL_Keycode k);
  void moveTetriminoOnY(Layout& l);

protected:
  SDL_FRect m_baseSqaure;
  SDL_FRect m_pivot;
  std::vector<SDL_FRect> m_outter;
};

class O_Tetrimino : public Tetrimino {

  O_Tetrimino() : Tetrimino(TETRIMINO_O) {}
};
class T_Tetrimino : public Tetrimino {
  T_Tetrimino() : Tetrimino(TETRIMINO_T) {}
};
class J_Tetrimino : public Tetrimino {
  J_Tetrimino() : Tetrimino(TETRIMINO_J) {}
};
class K_Tetrimino : public Tetrimino {
  K_Tetrimino() : Tetrimino(TETRIMINO_K) {}
};
class S_Tetrimino : public Tetrimino {
  S_Tetrimino() : Tetrimino(TETRIMINO_S) {}
};
class Z_Tetrimino : public Tetrimino {
  Z_Tetrimino() : Tetrimino(TETRIMINO_Z) {}
};
