#include "game.hpp"
#include "drawing.hpp"
#include "FindingNemo.hpp"
#include <vector>
#include <time.h>
#include <iostream>
// #include <SDL_ttf.h>

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Renderer *Drawing::hRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;

Game gPromptTextTexture;
Game gInputTextTexture;

static int screen;

bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Finding Nemo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
				// else{
				// 	cout << "song";
				// }
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	Drawing::assets = loadTexture("Combined_assets.png");
	screen = 1;
	gTexture = loadTexture("FirstScreen.png");
	if (Drawing::assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	
	gMusic = Mix_LoadMUS("bg_music.mp3");
	if (gMusic == NULL)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	// else{
	// 	cout << "song";
	// }
	return success;
}

// bool Game::BackgroundScreen()
// {
// 	// Loading success flag
// 	bool success = true;
// 	screen = 2;
// 	gTexture = loadTexture("bg.png");
// 	if (gTexture == NULL)
// 	{
// 		printf("Unable to run due to error: %s\n", SDL_GetError());
// 		success = false;
// 	}
// 	return success;
// }
bool Game::HardScreen()
{
	// Loading success flag
	bool success = true;
	screen = 2;
	gTexture = loadTexture("bg.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
bool Game::MediumScreen()
{
	// Loading success flag
	bool success = true;
	screen = 7;
	gTexture = loadTexture("bg.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
bool Game::EasyScreen()
{
	// Loading success flag
	bool success = true;
	screen = 6;
	gTexture = loadTexture("bg.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
bool Game::FirstScreen()
{
	// Loading success flag
	bool success = true;
	screen = 1;
	gTexture = loadTexture("FirstScreen.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::RulesScreen()
{
	// Loading success flag
	bool success = true;
	screen = 3;
	gTexture = loadTexture("RulesScreen.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::LevelsScreen()
{
	// Loading success flag
	bool success = true;
	screen = 5;
	gTexture = loadTexture("LevelsScreen.jpeg");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::EndScreen()
{
	// Loading success flag
	bool success = true;
	screen = 4;
	gTexture = loadTexture("EndScreen.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}



void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets = NULL;
	SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	// Mix_FreeMusic(gMusic);
	gMusic = NULL;
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;
	int xMouse, yMouse;

	Finding_Nemo *fn = new Finding_Nemo();
	while( !quit )
	{
		int xMouse, yMouse;
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if (xMouse > 401 && xMouse < 498 && yMouse > 368 && yMouse < 423 && screen == 1)
				{
					// cout << "Play" << endl;
					LevelsScreen();
				}
				if (xMouse > 381 && xMouse < 513 && yMouse > 449 && yMouse < 489 && screen == 1)
				{
					RulesScreen();
				}
				if (xMouse >= 394 && xMouse <= 499 && yMouse >= 533 && yMouse <= 585 && screen == 1)
				{
					quit = true;
				}
				if (xMouse >= 615 && xMouse <= 859 && yMouse >= 280 && yMouse <= 345 && screen == 5)
				{
					HardScreen();
				}
				if (xMouse >= 355 && xMouse <= 600 && yMouse >= 280 && yMouse <= 345 && screen == 5)
				{
					MediumScreen();
				}
				if (xMouse >= 90 && xMouse <= 344 && yMouse >= 280 && yMouse <= 345 && screen == 5)
				{
					EasyScreen();
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && (screen == 2 || screen == 3 || screen == 4 || screen == 6 || screen == 7 || screen == 10))
			{
				gTexture = loadTexture("FirstScreen.png");
				screen = 1;
			}
			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p && (screen == 2 || screen == 6 || screen == 7))
			{
				if (fn->paused == false)
				{
					fn->paused = true;
					cout << "Paused! You can catch your breath" << endl;
				}
				else if (fn->paused == true) 
				{
					fn->paused = false;
					cout << "Unpaused! Let's find Nemo" << endl;
				}
			}
			if (e.type == SDL_MOUSEMOTION && screen == 2 || screen == 1 || screen == 5 || screen == 6 || screen == 7)
			{
				SDL_GetMouseState(&xMouse, &yMouse);
				// cout << xMouse << " " << yMouse << endl;
				fn->checkMouseClick(xMouse, yMouse);
			}
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(gMusic, -1);
			}
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		if (fn->Life.life > 0 && fn->paused == false)
		{
			//Hard level
			if (screen == 2)
			{
				fn->createObject(xMouse, yMouse);
				fn->draw_Objects();
				fn->create_smallfish();
				fn->draw_smallfish();
				fn->create_hook_Hard();
				fn->draw_hook();
				fn->create_Shark1_Hard();
				fn->create_Shark2_Hard();
				fn->draw_Shark1();
				fn->draw_Shark2();
				fn->draw_lives();
				fn->show_score();
				fn->collision_dhuzzz();
				fn->delete_Objects();
			}
			// Medium Level
			if (screen == 7)
			{
				fn->createObject(xMouse, yMouse);
				fn->draw_Objects();
				fn->create_smallfish();
				fn->draw_smallfish();
				fn->create_hook_Medium();
				fn->draw_hook();
				fn->create_Shark1_Medium();
				fn->create_Shark2_Medium();
				fn->draw_Shark1();
				fn->draw_Shark2();
				fn->draw_lives();
				fn->show_score();
				fn->collision_dhuzzz();
				fn->delete_Objects();
			}
			// Easy Level
			if (screen == 6)
			{
				fn->createObject(xMouse, yMouse);
				fn->draw_Objects();
				fn->create_smallfish();
				fn->draw_smallfish();
				fn->create_hook_Easy();
				fn->draw_hook();
				fn->create_Shark1_Easy();
				// fn->create_Shark2();
				fn->draw_Shark1();
				// fn->draw_Shark2();
				fn->draw_lives();
				fn->show_score();
				fn->collision_dhuzzz();
				fn->delete_Objects();
			}
		}
		else 
		{
			if (fn->Life.life <= 0)
			{
				EndScreen();
				fn->Life.life = 3;
			}
		}
		
		//****************************************************************
		if(fn->paused == false)SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
		
	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}




