#include<SDL.h>
#include "drawing.hpp"
#pragma once

class Shark2{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void swim();
    bool del_shark();
    Shark2(int);
    Shark2(SDL_Rect s)
    {
        moverRect = s;
    }
    
};
