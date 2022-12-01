#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Shark2 : public Swimming_Object{
    private:
    SDL_Rect src, mover;
    int type;
    
    public:
    
    void set_type(int);
    int get_type();
    void swim(int);
    bool del_shark();
    Shark2(int, int);
        
};
