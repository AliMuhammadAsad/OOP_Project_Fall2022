#pragma once
#include <SDL.h>
#include "drawing.hpp"

class Lives{
    protected:
    SDL_Rect srcRect, moverRect;
    int life = 3;
    public:
    Lives();
    void draw();
    void operator--(); //operator overloading for decreasing lives
};