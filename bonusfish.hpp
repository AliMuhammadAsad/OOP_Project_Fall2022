#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once
class BonusFish : public Swimming_Object
{
    private:
    SDL_Rect src, mover;
    public:
    void swim();
    BonusFish(); 
    BonusFish(int);
    bool del_bonusfish();
    void set_to_del();
};

