#include "shark2.hpp"
#include<vector>
#include<list>
#include<SDL.h>
// pigeon implementation will go here.
// vector<Pigeon*> pigeons;
// void Shark2::draw(){
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
//     // SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect);
// }

Shark2::Shark2(int x, int y) : Swimming_Object({34, 2159, 188, 101}, {x, y, 100, 100}){}

void Shark2::swim(int type){
    // you have to do flying animations here
        // moverRect.x+=5;
        // if (screen == 2)
        // {
        // }
        int z = moverRect.x % 3;
        if(type == 0){
            if (z==0) srcRect = {34, 2159, 188, 101};
            if (z==1) srcRect = {292, 2159, 200, 101};
            if (z==2) srcRect = {566, 2159, 200, 101};
            moverRect.x+=5;
        }
        else if(type == 1){
            if(z == 0) srcRect = {1374, 2277, 188, 101};
            else if(z == 1) srcRect = {1162, 2276, 200, 101};
            else if(z == 2) srcRect = {944, 2280, 200, 101};
            moverRect.x -= 5;
        }
}

// Shark2::Shark2(int y){
//     // src coorinates from assets.png file, they have been found using spritecow.com
//     srcRect = {34, 2159, 188, 101};

//     // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
//     moverRect = {0, y, 100, 100};
// }

bool Shark2::del_shark(){
    if(moverRect.x > 1000 || moverRect.x < 0) return true;
    else return false;
}

void Shark2::set_type(int t){
    type = t;
}

int Shark2::get_type(){
    return type;
}

