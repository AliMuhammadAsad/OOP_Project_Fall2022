#include "smallfish.hpp"

Smallfish::Smallfish(int y) : Swimming_Object({954,1535,28,21}, {0, y, 30, 40}) {}

void Smallfish::swim(){
       moverRect.x+=5;
       moverRect.y+=1;
       int z = moverRect.x % 3;
        if (z==0) srcRect = {954,1535,28,21};
        if (z==1) srcRect = {1000, 1534, 30, 21};
        if (z==2) srcRect = {1048, 1532, 30, 21};
}

bool Smallfish::del_smallfish(){
    if(moverRect.x >= 1000 || moverRect.y >= 580) return true;
    else return false;
}



