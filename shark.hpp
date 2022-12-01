#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
// #include "game.hpp"
#pragma once

class Shark : public Swimming_Object{
    private:
    SDL_Rect src, mover;
    int type;
    
    public:
    
    void set_type(int);
    int get_type();
    void swim(int);
    Shark();
    Shark(int, int);
    bool del_shark(); 
};
