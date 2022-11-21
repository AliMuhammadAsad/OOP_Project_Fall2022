#include<SDL.h>
#include "drawing.hpp"
#pragma once

class Shark2{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void swim();
    Shark2();
    Shark2(SDL_Rect s)
    {
        moverRect = s;
    }
    // you may add other overloaded constructors here... 
};
