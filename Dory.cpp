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
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {800,1837,199,166};
    // it will display dory on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {30, 40, 50, 50};

    // srcRect = {1,1,199,166};
    // // it will display dory on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    // moverRect = {30, 40, 50, 50};

}

void Dory::setMov(int x, int y)
{
    moverRect.x = x; //moving the dory on x coordinates
    moverRect.y = y; //moving the dory on y coordinates
}

SDL_Rect Dory::getMov(){
    return moverRect;
}

