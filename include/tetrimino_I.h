

#pragma once

#include "layout.h"
#include "tetrimino.h"
#include <SDL3/SDL_rect.h>
#include <cassert>

class I_Tetrimino : public Tetrimino {

public:
  I_Tetrimino() : Tetrimino(TETRIMINO_I) {
    m_baseSqaure = {};
    m_pivot = {};
    m_outter = {
        SDL_FRect{
            0.f,
            0.f,
            Config::cellSize,
            Config::cellSize,
        },
        SDL_FRect{
            40.f,
            0.f,
            Config::cellSize,
            Config::cellSize,
        },
        SDL_FRect{
            80.f,
            0.f,
            Config::cellSize,
            Config::cellSize,
        },
        SDL_FRect{
            120.f,
            0.f,
            Config::cellSize,
            Config::cellSize,
        },

    };
    m_allRects = m_outter;

    assert(m_allRects.size() == 4 && "Rect Size on constructor isn't length 4");

  } // End Constructor

}; // namespace Color_I=classI_Tetrimino:public Tetrimino
