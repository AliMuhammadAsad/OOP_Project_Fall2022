#include "smallfish.hpp"
// pigeon implementation will go here.

// void Smallfish::draw(){
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

// }
Smallfish::Smallfish(int y) : Swimming_Object({954,1535,28,21}, {0, y, 30, 40}) {}

void Smallfish::swim(){
    // you have to do flying animations here
       moverRect.x+=5;
       moverRect.y+=1;
       int z = moverRect.x % 3;
        if (z==0)
        {
            srcRect = {954,1535,28,21};
        }
        if (z==1)
        {
            srcRect = {1000, 1534, 30, 21};
        }
        if (z==2)
        {
            srcRect = {1048, 1532, 30, 21};
        }
        // if (moverRect.x > 1000) // rotates pigeon across the screen
        // {
        //     moverRect.x = 0;
        // }
}

bool Smallfish::del_smallfish(){
    if(moverRect.x >= 1000 || moverRect.y >= 580) return true;
    else return false;
}
// deleting memory
// void Smallfish::remove_smallfish() //removing bullets
// {
//     moverRect = {0, 0, 0, 0};
// }
// Smallfish::Smallfish(){
//     // src coorinates from assets.png file, they have been found using spritecow.com
//     srcRect = {800,0,50,42};

//     // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
//     moverRect = {200, 40, 30, 30};
// }


