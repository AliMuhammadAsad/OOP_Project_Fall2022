#include"bonusfish.hpp"

BonusFish::BonusFish(int y) : Swimming_Object({23, 1665, 50, 35}, {0, y, 30, 40}){}

void BonusFish::swim(){
    moverRect.x += 10;
    int z = moverRect.x % 3;
    if(z == 0) srcRect = {23, 1665, 50, 35};
    else if(z == 1) srcRect = {85, 1665, 51, 35};
    else if(z == 2) srcRect = {157, 1666, 49, 35};
}

bool BonusFish::del_bonusfish(){
    if(moverRect.x > 1000 || moverRect.y > 600) return true;
    else return false;
}

void BonusFish::set_to_del(){
    moverRect = {1100, 610, 30, 40};
}