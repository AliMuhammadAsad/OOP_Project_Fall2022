#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "FindingNemo.hpp"
// #include "score.hpp"

class Game{
    // Screen dimension constants
    const int SCREEN_WIDTH = 939;
    const int SCREEN_HEIGHT = 626;

    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    // Current displayed texture
    SDL_Texture *gTexture = NULL;

    // The music that will be played
    Mix_Music *gMusic = NULL;

    // SDL_ttf *ftexture = NULL;
    // TTF_Font* font = NULL;
    Game();
    ~Game();

    static Game* ptr;

    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

    public:
    bool init();
    bool loadMedia();
    
    void close();
    
    SDL_Texture *loadTexture(std::string path);
    
    void run();
    
    bool FirstScreen();
    bool HardScreen();
    bool RulesScreen();
    bool LevelsScreen();
    bool EasyScreen();
    bool MediumScreen();
    bool EndScreen();
    bool WinningScreen();
    
    bool R1();
    bool R2();
    bool R3();
    bool R4();
    bool R5();
    
    static Game* getPointer();
    
    void show_time(int);
};
