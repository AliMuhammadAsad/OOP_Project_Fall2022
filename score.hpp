#pragma once

class Score{
    public:
    int score;
    
    public:
    Score(int); //constructor
    int getScore(); //getter function for score
    void operator++(); //operator overload  //adds points to the score
};