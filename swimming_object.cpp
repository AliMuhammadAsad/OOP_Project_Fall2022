#include "swimming_object.hpp"

Swimming_Object::Swimming_Object(SDL_Rect src, SDL_Rect mover){
    srcRect = src; moverRect = mover; //setting srcRect and moverRect values
}

void Swimming_Object::swim(){};

void Swimming_Object::draw(){ //draw function to be inherited by all child classes
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

SDL_Rect Swimming_Object::getMov(){
    return moverRect; //getting moverRect value
}
