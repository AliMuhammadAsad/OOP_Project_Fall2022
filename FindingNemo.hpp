#include<SDL.h>
#include "drawing.hpp"
#include "swimming_object.hpp"
#include "Dory.hpp"
#include "smallfish.hpp"
#include "lives.hpp"
#include "score.hpp"
#include<vector>
#include<list>
using namespace std;

class Finding_Nemo{

    int score = 0;
    //Right now we're creating one pigeon, 
    // Dory *dory;
    Dory d1;
    Smallfish s1;
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Smallfish*> smallfishes;
    // In the solution you have to create vectors of pigeons, eggs, and nests    


    public:
    Lives Life;

    // Finding_Nemo();

    // void draw_lives();
    void drawObjects(); 
    void createObject(int, int);
    void checkMouseClick(int, int);
};