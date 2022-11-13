#include<SDL.h>
#include <iostream>
#include "FindingNemo.hpp"
#include<vector>
#include<list>
using namespace std;

void Finding_Nemo::drawObjects()
{
    // call draw functions of all the objects here
    // dory->draw();
    // dory->swim(); // this function is called to move the pigeon
    d1.draw();
    // d1.swim();
}

void Finding_Nemo::createObject(int x, int y)
{
    cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void Finding_Nemo::checkMouseClick(int x, int y)
{
    // dory->setMov(x, y);
    d1.setMov(x, y);
}