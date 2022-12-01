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
#include<string>
#include<SDL_ttf.h>
#pragma once
using namespace std;

class Finding_Nemo{
    private:
    int score = 0;
    //Right now we're creating one pigeon, 
    // Dory *dory;
    Dory *dory;
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
    // Score s;
    Finding_Nemo();

    // void draw_lives();
    void checkMouseClick(int, int);
    void createObject(int, int);
    void create_Shark1_Hard();
    void create_Shark1_Medium();
    void create_Shark1_Easy();
    void create_Shark2_Hard();
    void create_Shark2_Medium();
    void create_smallfish();
    void create_hook_Hard();
    void create_hook_Medium();
    void create_hook_Easy();
    void draw_Objects(); 
    void draw_Shark1();
    void draw_Shark2();
    void draw_smallfish();
    void draw_hook();
    void draw_lives();
    void show_score();
    void collision_dhuzzz();
    void delete_Objects();
    int get_score();
};