#include "Dory.hpp"
// pigeon implementation will go here.

void Dory::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

}

void Dory::fly(){
    // you have to do flying animations here
    moverRect.x += 5;
}

Dory::Dory(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0,0,200,167};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
}

