#include<SDL.h>
#include "drawing.hpp"
class Smallfish 
{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void swim();
    Smallfish(); 

    // you may add other overloaded constructors here... 
};
