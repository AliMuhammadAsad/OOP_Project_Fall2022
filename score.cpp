#include "score.hpp"

Score::Score(int init_score) : score(init_score){};

int Score::getScore(){
    return score; //getting the score to be displayed etc
}

void Score::operator++(){
    score = score + 10; //whatever amount we wanna add to the score on eating a fish - 10 is a dummy value for now 
}