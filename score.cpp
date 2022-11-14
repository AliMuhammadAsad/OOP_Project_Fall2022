#include "score.hpp"

Score::Score(int init_score) : s_score(init_score){};

void Score::AddScore(){
    s_score += 1; //whatever amount we wanna add to the score on eating a fish - 1 is a dummy value for now
}

int Score::getScore(){
    return s_score; //getting the score to be displayed etc
}