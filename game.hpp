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

class Game
{
    // Screen dimension constants
    const int SCREEN_WIDTH = 939;
    const int SCREEN_HEIGHT = 626;

    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    // Current displayed texture
    SDL_Texture *gTexture = NULL;

    // The music that will be played
    Mix_Music *gMusic = NULL;

public:
    bool init();
    bool loadMedia();
    // SDL_Texture *Mix_LoadMUS(std::string path);
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
    bool FirstScreen();
    bool PlayScreen();
    bool RulesScreen();
    // bool MediumScreen();
    // bool HardScreen();
    bool EndScreen();
};
