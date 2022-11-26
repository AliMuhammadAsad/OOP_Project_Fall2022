#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#pragma once
class Smallfish : public Swimming_Object
{
    private:
    // SDL_Rect srcRect, moverRect;
    SDL_Rect src, mover;
public:
    // void draw();
    void swim();
    Smallfish(); 
    Smallfish(int);
<<<<<<< Updated upstream
    // void remove_Smallfish(); 
=======
>>>>>>> Stashed changes
    // you may add other overloaded constructors here... 
};

