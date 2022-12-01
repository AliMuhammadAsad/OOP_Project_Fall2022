#include "shark.hpp"
#include<vector>
#include<list>
#include<SDL.h>

Shark::Shark(int x, int y) : Swimming_Object({34, 1867, 188, 101}, {x, y, 100, 100}) {}

void Shark::swim(int type){
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
}

bool Shark::del_shark(){
    if(moverRect.x >= 1000  || moverRect.x <= 0) return true;
    else return false;
}

void Shark::set_type(int t){
    type = t;
}

int Shark::get_type(){
    return type;
}



