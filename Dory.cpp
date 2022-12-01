#include "Dory.hpp"
// pigeon implementation will go here.

void Dory::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

}

void Dory::swim(){
    // you have to do flying animations here
    moverRect.x += 5;
}

Dory::Dory(){
    srcRect = {800,1837,199,166};
    moverRect = {30, 40, 40, 40};
}

void Dory::setMov(int x, int y)
{
    moverRect.x = x; //moving the dory on x coordinates
    moverRect.y = y; //moving the dory on y coordinates
}

SDL_Rect Dory::getMov(){
    return moverRect;
}
