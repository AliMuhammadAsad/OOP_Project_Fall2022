#include<SDL.h>
#include "Dory.hpp"
#include "smallfish.hpp"
#include<vector>
#include<list>
using namespace std;

class Finding_Nemo{

    //Right now we're creating one pigeon, 
    Dory d1;
    Smallfish s1;
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Dory*> dorys;
    vector<Smallfish*> smallfishes;

    public:
    void drawObjects(); 
    void createObject(int, int);
    
};