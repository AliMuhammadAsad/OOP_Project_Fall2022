#include "smallfish.hpp"
// pigeon implementation will go here.

void Smallfish::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

}

void Smallfish::swim(){
    // you have to do flying animations here
       moverRect.x+=5;
        // pigeons[i].moverRect.y-=5;
        int z = moverRect.x % 3;
        if (z==0)
        {
            srcRect = {954, 1535, 28, 50};
        }
        if (z==1)
        {
            srcRect = {1000, 1534, 26, 50};
        }
        if (z==2)
        {
            srcRect = {1048, 1532, 28, 50};
        }
        if (moverRect.x > 1000) // rotates pigeon across the screen
        {
            moverRect.x = 0;
        }
}

Smallfish::Smallfish(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {954,1535,28,50};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {200, 40, 30, 30};
}



