#include<SDL.h>
#include <iostream>
#include "FindingNemo.hpp"
#include<vector>
#include<list>
using namespace std;

// Finding_Nemo::Finding_Nemo(){ //constructor for Finding_Nemo
//     dory = new Dory(); // This dynamically creates one obj of Dory 
// }


void Finding_Nemo::drawObjects()
{
    // call draw functions of all the objects here
    // if (screen == 1)
    d1.draw();
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

void Finding_Nemo::createObject(int x, int y)
{
    cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void Finding_Nemo::checkMouseClick(int x, int y)
{
    // dory->setMov(x, y);
    d1.setMov(x, y);
    
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

void Finding_Nemo::createShark1(){
    int y_cord = rand() % 550;
    int prob_gen = rand() % 50;
    if(prob_gen == 1){
        Shark* shark = new Shark(y_cord);
        sharks1.push_back(shark);
    }
}

void Finding_Nemo::drawShark1(){
    for(int i = 0; i < sharks1.size(); i++){
        sharks1[i]->draw(); sharks1[i]->swim();
    }
}

void Finding_Nemo::createShark2(){
    int y_cord = rand() % 550;
    int prob_gen = rand() % 50;
    if(prob_gen == 1){
        Shark2* shark = new Shark2(y_cord);
        sharks2.push_back(shark);
    }
}

void Finding_Nemo::drawShark2(){
    for(int i = 0; i < sharks2.size(); i++){
        sharks2[i]->draw(); sharks2[i]->swim();
    }
}

void Finding_Nemo::deleteObjects(){
    for(int s1c = 0; s1c < sharks1.size(); s1c++){
        if(sharks1[s1c]->del_shark() == true){
            delete sharks1[s1c]; sharks1.erase(sharks1.begin() + s1c);
            cout << "Shark1 has been deleted\n";
        }
    }
    for(int s2c = 0; s2c < sharks2.size(); s2c++){
        if(sharks2[s2c]->del_shark() == true){
            delete sharks2[s2c]; sharks2.erase(sharks2.begin() + s2c);
            cout << "Shark2 has been deleted\n";
        }
    }
}
