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