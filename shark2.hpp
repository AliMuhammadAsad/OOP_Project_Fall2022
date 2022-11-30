#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Shark2 : public Swimming_Object{
    private:
        SDL_Rect src, mover;

    public:
        int type;
        // void draw();
        void swim(int);
        bool del_shark();
        Shark2(int, int);
        // Shark2(SDL_Rect s)
        // {
        //     moverRect = s;
        // }
};
