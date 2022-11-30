#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Shark2 : public Swimming_Object{
    private:
        SDL_Rect src, mover;

    public:
        // void draw();
        void swim();
        bool del_shark();
        Shark2(int);
        // Shark2(SDL_Rect s)
        // {
        //     moverRect = s;
        // }
};
