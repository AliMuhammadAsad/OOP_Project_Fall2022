#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once
class Smallfish : public Swimming_Object{
    private:
    SDL_Rect src, mover;
    
    public:
    
    void swim();
    Smallfish(); 
    Smallfish(int);
    bool del_smallfish(); 
};

