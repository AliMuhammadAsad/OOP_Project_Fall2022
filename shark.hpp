#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Shark : public Swimming_Object{
    protected:
        SDL_Rect src, mover;
    public:
        int type;
        // void draw();
        void swim(int);
        Shark();
        Shark(int, int);
        bool del_shark();
        // Shark(SDL_Rect s)
        // {
        //     moverRect = s;
        // }
        // SDL_Rect getMov();
        // you may add other overloaded constructors here... 
};
