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
    // d1.fly(); // this function is called to move the pigeon
    sh1.draw();
    sh1.swim();
    h1.draw();
    h1.swim();
    s1.draw();
    s1.swim();
    sh2.draw();
    sh2.swim();
    // b1.draw();
    // b1.swim();
    // for (int i = 0; i < sharks.size(); i++)
    // {
    //     sharks[i]->draw(); // this function is called to draw the pigeon
    //     sharks[i]->swim(); // this function is called to move the pigeon
    // }
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