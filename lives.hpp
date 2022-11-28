#pragma once
#include <SDL.h>
#include "drawing.hpp"

class Lives{
    protected:
    SDL_Rect srcRect, moverRect;
    public:
    int life = 3;
    Lives();
    void draw();
    void operator--(); //operator overloading for decreasing lives
    void operator++();
};