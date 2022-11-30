#include "shark.hpp"
#include<vector>
#include<list>
#include<SDL.h>
// pigeon implementation will go here.
// vector<Pigeon*> pigeons;
// void Shark::draw(){
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
//     // SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect);
// }

Shark::Shark(int x, int y) : Swimming_Object({34, 1867, 188, 101}, {x, y, 100, 100}) {}

void Shark::swim(int type){
    // you have to do flying animations here
        // moverRect.x+=5;
        // switch(frame){
        //     case 0: srcRect = {34, 1867, 188, 101}; frame = 1; break;
        //     case 1: srcRect = {292, 1867, 200, 101}; frame = 2; break;
        //     case 2: srcRect = {566, 1867, 200, 101}; frame = 0; break;
        // }
        int z = moverRect.x % 3;
        if(type == 0){
            if (z==0) srcRect = {34, 1867, 188, 101};
            else if (z==1) srcRect = {292, 1867, 200, 101};
            else if (z==2) srcRect = {566, 1867, 200, 101};
            moverRect.x += 5;
        }
        else if(type == 1){
            if(z == 0) srcRect = {1372, 2140, 188, 101};
            else if(z == 1) srcRect = {1160, 2139, 200, 101};
            else if(z == 2) srcRect = {942, 2143, 200, 101};
            moverRect.x -= 5;
        }
        // if (moverRect.x > 1000) // rotates pigeon across the screen
        // {
        //     moverRect.x = 0;
        // }
    // moverRect.x += 5;
}

bool Shark::del_shark(){
    if(moverRect.x > 1000 || moverRect.x < 0) return true;
    else return false;
}

// Shark::Shark(int y){
//     // src coorinates from assets.png file, they have been found using spritecow.com
//     srcRect = {34, 1867, 188, 101};

//     // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
//     moverRect = {0, y, 100, 100};
// }

// SDL_Rect Shark::getMov(){
//     return moverRect;
// }



