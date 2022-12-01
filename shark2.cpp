#include "shark2.hpp"
#include<vector>
#include<list>
#include<SDL.h>

Shark2::Shark2(int x, int y) : Swimming_Object({34, 2159, 188, 101}, {x, y, 100, 100}){}

void Shark2::swim(int type){
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

