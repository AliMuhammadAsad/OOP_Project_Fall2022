#include "lives.hpp"

Lives::Lives(){
    srcRect = {2, 617, 94, 26}; //cordinates of lives
    moverRect = {20, 20, 90, 30}; //coordinates for placing lives according to the game screen
}

void Lives::draw(){
    /*drawing the life according to the number of lives we have left.
    depending on the number of lives, that many lives from either the assets file or the life file will be displayed
    and the moverrect width will be changed accordingly, or can be left same, will check once implemented.*/
    switch(life){
        case 3: {srcRect = {2, 617, 94, 26}; moverRect.w = 90; break;}
        case 2: {srcRect = {2, 617, 62, 25}; moverRect.w = 60; break;}
        case 1: {srcRect = {2, 617, 29, 25}; moverRect.w = 30; break;}
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Lives::operator--(){
    life = life - 1;
}
void Lives::operator++(){
    life = life + 1;
}