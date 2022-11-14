#include "lives.hpp"

Lives::Lives(){
    srcRect = {}; //cordinates of lives
    moverRect = {}; //coordinates for placing lives according to the game screen
}

void Lives::draw(){
    /*drawing the life according to the number of lives we have left.
    depending on the number of lives, that many lives from either the assets file or the life file will be displayed
    and the moverrect width will be changed accordingly, or can be left same, will check once implemented.*/
    switch(life){
        case 3: srcRect = {}; moverRect = {}; break;
        case 2: srcRect = {}; moverRect = {}; break;
        case 1: srcRect = {}; moverRect = {}; break;
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Lives::operator--(){
    life = life - 1;
}