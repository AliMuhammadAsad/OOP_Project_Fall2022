#include<SDL.h>
#include "drawing.hpp"
#pragma once

class Shark{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void swim();
    bool del_shark();
    Shark(int);
    Shark(SDL_Rect s)
    {
        moverRect = s;
    }
    // you may add other overloaded constructors here... 
};
