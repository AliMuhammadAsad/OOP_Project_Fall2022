#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Shark : public Swimming_Object{
    private:
        SDL_Rect src, mover;
    public:
        // void draw();
        void swim();
        Shark();
        Shark(int);
        bool del_shark();
        // Shark(SDL_Rect s)
        // {
        //     moverRect = s;
        // }
        // SDL_Rect getMov();
        // you may add other overloaded constructors here... 
};
