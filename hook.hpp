#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Hook : public Swimming_Object
{
private:
    SDL_Rect src, mover;

public:
    void swim();
    Hook();
    Hook(int);
    // you may add other overloaded constructors here... 
};
