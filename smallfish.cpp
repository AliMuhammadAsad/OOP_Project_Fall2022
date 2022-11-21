#include "smallfish.hpp"
// pigeon implementation will go here.

void Smallfish::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

}

void Smallfish::swim(){
    // you have to do flying animations here
       moverRect.y+=5;
        // pigeons[i].moverRect.y-=5;
        int z = moverRect.x % 3;
        if (z==0)
        {
            srcRect = {2414, 0, 28, 50};
        }
        if (z==1)
        {
            srcRect = {2466, 0, 26, 50};
        }
        if (z==2)
        {
            srcRect = {2514, 0, 28, 50};
        }
        if (moverRect.y > 1000) // rotates pigeon across the screen
        {
            moverRect.y = 0;
        }
}

Smallfish::Smallfish(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0,0,260,194};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {200, 40, 30, 30};
}



