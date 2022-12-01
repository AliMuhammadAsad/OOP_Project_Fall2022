#include "hook.hpp"
#include<vector>
#include<list>
#include<SDL.h>

Hook::Hook(int x) : Swimming_Object({800,612,23,80}, {x, 0, 30, 40}) {}

void Hook::swim(){
    moverRect.y+=5;
    srcRect = {800, 612, 23, 80};
}

bool Hook::del_hook(){
    if(moverRect.y >= 580) return true;
    else return false;
}

