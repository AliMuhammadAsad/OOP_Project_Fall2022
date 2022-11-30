#include<SDL.h>
#include <iostream>
#include "FindingNemo.hpp"
#include<vector>
#include<list>
#include<SDL_ttf.h>
using namespace std;

Finding_Nemo::Finding_Nemo(){
    dory = new Dory();
}

void Finding_Nemo::checkMouseClick(int x, int y)
{
    // dory->setMov(x, y);
    dory->setMov(x, y);
}

// Finding_Nemo::Finding_Nemo(){ //constructor for Finding_Nemo
//     dory = new Dory(); // This dynamically creates one obj of Dory 
// }

/*--------------------------------------------------------------------------------------------------------------*/
//The Big Bang - Here creation of our objects first began and we made molds of what we wanted to create

void Finding_Nemo::createObject(int x, int y)
{
    // cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void Finding_Nemo::create_smallfish()
{
    int n = rand() % 550;
    int p = rand() % 30; //probability of generation
    if (p == 1)
    {
        Smallfish *s1 = new Smallfish(n); //dynamically creating objects
        smallfishes.push_back(s1); //pushing back objects
    }
}

void Finding_Nemo::create_bonusfish(){
    int n = rand() % 550;
    int p = rand() % 200;
    if(p == 1){
        BonusFish *b1 = new BonusFish(n);
        bonusfish.push_back(b1);
    }
}

void Finding_Nemo::create_hook()
{
    int n = rand() % 550;
    int p = rand() % 30; //probability of generation
    if (p == 1)
    {
        Hook *h1 = new Hook(n); //dynamically creating objects
        hooks.push_back(h1); //pushing back objects
    }
}

void Finding_Nemo::create_Shark1(){
    int y_cord = rand() % 550;
    int prob_gen = rand() % 50;
    int t = rand() % 2;
    if(prob_gen == 1){
        if(t == 0){
            Shark* shark = new Shark(0, y_cord);
            shark->type = 0;
            sharks1.push_back(shark);
        }
        else if(t == 1){
            Shark* shark = new Shark(1000, y_cord);
            shark->type = 1;
            sharks1.push_back(shark);
        }
    }
}

void Finding_Nemo::create_Shark2(){
    int y_cord = rand() % 550;
    int prob_gen = rand() % 50;
    int t = rand() % 2;
    if(prob_gen == 1){
        if(t == 0){
            Shark2* shark = new Shark2(0, y_cord);
            shark->type = 0;
            sharks2.push_back(shark);
        }
        else if(t == 1){
            Shark2* shark = new Shark2(1000, y_cord);
            shark->type = 1;
            sharks2.push_back(shark);
        }
    }
}

/*--------------------------------------------------------------------------------------------------------------*/
//Drawing Section - Here life was breathed into our molds and objects, and henceforth they sprang with life and swam with joy exploring the vastness of the world's oceans 

void Finding_Nemo::draw_Objects()
{
    // call draw functions of all the objects here
    // if (screen == 1)
    dory->draw();
    // sh1.draw();
    // sh1.swim();
    // sh2.draw();
    // sh2.swim();
 
}

void Finding_Nemo::draw_smallfish()
{
    for (auto &s1 : smallfishes) // initializing small fish
    {
        s1->draw(); // calling the draw functionality in the small asteroids
        s1->swim();  // calling the fly functionality in the fly function
    }
}

void Finding_Nemo::draw_bonusfish(){
    for(auto &b1 : bonusfish){
        b1->draw();
        b1->swim();
    }
}

void Finding_Nemo::draw_hook()
{
    for (auto &h1 : hooks) // initializing small fish
    {
        h1->draw(); // calling the draw functionality in the small asteroids
        h1->swim();  // calling the fly functionality in the fly function
    }
}

// void Finding_Nemo::draw_lives(){
//     Life.draw();
// }

void Finding_Nemo::draw_Shark1(){
    // for(int i = 0; i < sharks1.size(); i++){
    //     sharks1[i]->draw(); sharks1[i]->swim();
    // }
    for(auto &s1 : sharks1){
        s1->draw(); 
        s1->swim(s1->type);
    }
}

void Finding_Nemo::draw_Shark2(){
    for(auto &s2 : sharks2){
        s2->draw();
        s2->swim(s2->type);
    }
}

void Finding_Nemo::draw_lives(){
    Life.draw();
}

/*--------------------------------------------------------------------------------------------------------------*/
//Deletion Section - Not everything can last forever. This is the place where our beloved objects go to die, forgotten, floating in the endless void for eternity - alone and scared.

void Finding_Nemo::collision_dhuzzz(){

    //Initializing Dory here
    dory->draw(); SDL_Rect dor = dory->getMov();
    
    //Collision with Shark type 1
    for(auto &s1c : sharks1){
        SDL_Rect s1 = s1c->getMov();
        if(SDL_HasIntersection(&dor, &s1)){
            cout << "Dory has collided with a shark but its okay as they friends for now\n";
            --Life;
        }
    }

    //Collision with Shark type 2
    for(auto &s2c : sharks2){
        SDL_Rect s2 = s2c->getMov();
        if(SDL_HasIntersection(&dor, &s2)){
            cout << "Dory has collided with a shark 2 but its okay as they friends for now\n";
            --Life;
        }
    }

    //Collission with smallfishes
    for(auto &sfc : smallfishes){
        SDL_Rect sf = sfc->getMov();
        if(SDL_HasIntersection(&dor, &sf)){
            cout << "Dory has collided with a smallfish. Dory will proceed to eat the fish now\n";
            score += 10;
            sfc->set_to_del();
            cout <<"Your score is: " << score << endl;
        }
    }

    //Collision with Bonus Fish
    for(auto &bfc : bonusfish){
        SDL_Rect bf = bfc->getMov();
        if(SDL_HasIntersection(&dor, &bf)){
            cout << "Dory has collided with the bonus fish. Bonus fish helps dory, score + 50\n";
            score += 50;
            bfc->set_to_del();
            cout << "Your score is: " << score << endl;
        }
    }

    //Collision with hooks
    for(auto &hc : hooks){
        SDL_Rect h = hc->getMov();
        if(SDL_HasIntersection(&dor, &h)){
            cout << "Dory has been hit with a hook. Noooooooooooooooooo\n";
            --Life;
            hc->set_to_del();
        }
    }
}

void Finding_Nemo::show_score(){
    // SDL_Init();
    TTF_Init(); //Initializes SDL_TTF for displaying text in 
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24); //Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0}; //This is the texts color that can be changed using RGB values from 0 to 255.
    string tmp = to_string(score); //converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color); //A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); //Converts into texture that can be displayed
    SDL_Rect Message_rect = {20, 50, 90, 30}; //create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}



void Finding_Nemo::delete_Objects(){
    
    for(int s1c = 0; s1c < sharks1.size(); s1c++){ //s1c means Shark1 Check
        if(sharks1[s1c]->del_shark() == true){
            delete sharks1[s1c]; sharks1.erase(sharks1.begin() + s1c);
            cout << "Shark1 has been deleted. It will now float alone in the endless void for eternity.\n";
        }
    }
    
    for(int s2c = 0; s2c < sharks2.size(); s2c++){ //s2c means Shark2 Check
        if(sharks2[s2c]->del_shark() == true){
            delete sharks2[s2c]; sharks2.erase(sharks2.begin() + s2c);
            cout << "Shark2 has been deleted. It will now float alone in the endless void for eternity.\n";
        }
    }
    
    for(int sfc = 0; sfc < smallfishes.size(); sfc++){ //sfc = smallfishes check
        if(smallfishes[sfc]->del_smallfish() == true){
            delete smallfishes[sfc]; smallfishes.erase(smallfishes.begin() + sfc);
            cout << "Smallfish has been deleted. It will now float alone in the endless void for eternity.\n";
        }
    }

    for(int bfc = 0; bfc<bonusfish.size(); bfc++){
        if(bonusfish[bfc]->del_bonusfish() == true){
            delete bonusfish[bfc]; bonusfish.erase(bonusfish.begin() + bfc);
            cout << "Bonus Fish has been deleted. It will now float in the endless void for eternity.\n";
        }
    }

    for(int h = 0; h < hooks.size(); h++){
        if(hooks[h]->del_hook() == true){
            delete hooks[h]; hooks.erase(hooks.begin() + h);
            cout << "Hook has been deleted. Hook is not a living thing so we don't care if it floats alone in the endless void.\n";
        }
    }
}
