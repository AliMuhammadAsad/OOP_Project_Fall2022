#include<SDL.h>
#include <iostream>
#include "FindingNemo.hpp"
#include<vector>
#include<list>
using namespace std;

void Finding_Nemo::drawObjects()
{
    // call draw functions of all the objects here
    d1.draw();
    d1.fly(); // this function is called to move the pigeon

}

void Finding_Nemo::createObject(int x, int y)
{
    cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}