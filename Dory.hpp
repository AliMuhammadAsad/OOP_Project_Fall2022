#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"

class Dory{

    SDL_Rect srcRect, moverRect;

    public:
    void draw();
    void swim();
    Dory(); 
    void setMov(int x,int y);
    SDL_Rect getMov(); 
};
