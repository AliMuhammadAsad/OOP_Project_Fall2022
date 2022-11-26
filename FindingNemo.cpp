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
    // sh1.draw();
    // sh1.swim();
    h1.draw();
    h1.swim();
    s1.draw();
    s1.swim();
    // sh2.draw();
    // sh2.swim();
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
        // if(sharks1[i]->del_shark() == true){
        //     delete sharks1[i]; sharks1.erase(sharks1.begin() + i);
        //     cout << "Shark1 has been deleted\n";
        // }
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
        // if(sharks2[i]->del_shark() == true){
        //     delete sharks2[i]; sharks2.erase(sharks2.begin() + i);
        //     cout << "Shark2 has been deleted\n";
        // }
    }
}

void Finding_Nemo::checkMouseClick(int x, int y)
{
    // dory->setMov(x, y);
    d1.setMov(x, y);
    
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