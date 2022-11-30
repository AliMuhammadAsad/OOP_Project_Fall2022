#include "hook.hpp"
#include<vector>
#include<list>
#include<SDL.h>
// pigeon implementation will go here.
// vector<Pigeon*> pigeons;
Hook::Hook(int x) : Swimming_Object({800,612,23,80}, {x, 0, 30, 40}) {}

void Hook::swim(){
    // you have to do flying animations here
        moverRect.y+=5;
        // pigeons[i].moverRect.y-=5;
        srcRect = {800, 612, 23, 80};
        // if (moverRect.y > 1000) // rotates pigeon across the screen
        // {
        //     moverRect.y = 0;
        // }

    // moverRect.x += 5;
}

bool Hook::del_hook(){
    if(moverRect.y >= 580) return true;
    else return false;
}

void Hook::set_to_del(){
    moverRect.y = 610;
}

// Hook::Hook(){
//     // src coorinates from assets.png file, they have been found using spritecow.com
//     srcRect = {800, 612, 23, 80};

//     // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
//     moverRect = {400, 20, 50, 50};
// }

