#include<SDL.h>
#include "drawing.hpp"
class Dory{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void swim();
    Dory(); 
    void setMov(int x,int y);
    SDL_Rect getMov();
    // you may add other overloaded constructors here... 
};
