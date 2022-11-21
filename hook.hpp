#include<SDL.h>
#include "drawing.hpp"
#pragma once

class Hook{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void swim();
    Hook();
    Hook(SDL_Rect s)
    {
        moverRect = s;
    }
    // you may add other overloaded constructors here... 
};
