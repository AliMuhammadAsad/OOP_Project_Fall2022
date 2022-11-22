#include "hook.hpp"
#include<vector>
#include<list>
#include<SDL.h>
// pigeon implementation will go here.
// vector<Pigeon*> pigeons;
void Hook::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    // SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect);
}

void Hook::swim(){
    // you have to do flying animations here
        moverRect.y+=5;
        // pigeons[i].moverRect.y-=5;
        if (moverRect.y > 1000) // rotates pigeon across the screen
        {
            moverRect.y = 0;
        }

    // moverRect.x += 5;
}

Hook::Hook(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {800, 612, 23, 80};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {400, 20, 50, 50};
}

