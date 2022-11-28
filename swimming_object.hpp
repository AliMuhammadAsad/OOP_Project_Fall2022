#pragma once
#include <SDL.h>
#include "drawing.hpp"

class Swimming_Object{
    protected:
    SDL_Rect srcRect, moverRect;

    public:
    Swimming_Object(SDL_Rect, SDL_Rect); //constructor
    void draw(); //draw that will be inherited by all child classes as is
    virtual void swim(); //virtual swim function that will be overrided by child classes - achieves polymorphism
    SDL_Rect getMov(); //getting Mover rect position
    void set_to_del();
};