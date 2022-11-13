#include "smallfish.hpp"
// pigeon implementation will go here.

void Smallfish::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

}

void Smallfish::fly(){
    // you have to do flying animations here
    moverRect.x += 5;
}

Smallfish::Smallfish(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0,0,150,122};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
}



