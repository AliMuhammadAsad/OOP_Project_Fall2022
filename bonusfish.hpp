#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once
class BonusFish : public Swimming_Object
{
    private:
    // SDL_Rect srcRect, moverRect;
    SDL_Rect src, mover;
    public:
    // void draw();
    void swim();
    BonusFish(); 
    BonusFish(int);
    bool del_bonusfish();
    void set_to_del();
    // void remove_Smallfish(); 
    // you may add other overloaded constructors here... 
};

