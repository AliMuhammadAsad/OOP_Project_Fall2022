#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#include "Dory.hpp"
#include "smallfish.hpp"
#include "lives.hpp"
#include "score.hpp"
#include "shark.hpp"
#include "shark2.hpp"
#include "hook.hpp"
#include "boat.hpp"
#include<vector>
#include<list>
#pragma once
using namespace std;

class Finding_Nemo{
    private:
    int score = 0;
    //Right now we're creating one pigeon, 
    // Dory *dory;
    Dory d1;
    // Smallfish s1;
    // Shark sh1;
    // Shark2 sh2;
    // Hook h1;
    // Boat b1;
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Smallfish*> smallfishes;
    vector<Shark*> sharks1;
    vector<Shark2*> sharks2;
    vector<Hook*> hooks;
    
    public:
    Lives Life;

    // Finding_Nemo();

    // void draw_lives();
    void checkMouseClick(int, int);
    void createObject(int, int);
    void createShark1();
    void createShark2();
    void create_smallfish();
    void create_hook();
    void drawObjects(); 
    void drawShark1();
    void drawShark2();
    void draw_smallfish();
    void draw_hook();
    void deleteObjects();
};