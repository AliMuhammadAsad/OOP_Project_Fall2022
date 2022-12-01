#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once

class Hook : public Swimming_Object{
    private:
    SDL_Rect src, mover;

    public:
    void swim();
    bool del_hook();
    Hook();
    Hook(int);
};
