#include "shark2.hpp"
#include<vector>
#include<list>
#include<SDL.h>
// pigeon implementation will go here.
// vector<Pigeon*> pigeons;
void Shark2::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    // SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect);
}

void Shark2::swim(){
    // you have to do flying animations here
        moverRect.x+=5;
        // pigeons[i].moverRect.y-=5;
        int z = moverRect.x % 3;
        if (z==0)
        {
            srcRect = {3234, 323, 188, 101};
        }
        if (z==1)
        {
            srcRect = {3492, 323, 200, 101};
        }
        if (z==2)
        {
            srcRect = {3766, 323, 200, 101};
        }
        if (moverRect.x > 1000) // rotates pigeon across the screen
        {
            moverRect.x = 0;
        }

    // moverRect.x += 5;
}

Shark2::Shark2(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {3234, 323, 188, 101};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {30, 300, 100, 100};
}



