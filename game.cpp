#include "game.hpp"
#include "drawing.hpp"
#include "FindingNemo.hpp"
#include <vector>
#include <time.h>
#include <iostream>

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;
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
				// if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				// {
				// 	printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				// 	success = false;
				// }
				// // else{
				// // 	cout << "song";
				// // }
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	Drawing::assets = loadTexture("resized_d1.png");
	screen = 1;
	gTexture = loadTexture("FirstScreen.png");
	if (Drawing::assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	// gMusic = Mix_LoadMUS("bg_music.mp3");
	// if (gMusic == NULL)
	// {
	// 	printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	// 	success = false;
	// }
	// // else{
	// // 	cout << "song";
	// // }
	return success;
}

bool Game::BackgroundScreen()
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

bool Game::FirstScreen()
{
	// Loading success flag
	bool success = true;
	screen = 4;
	gTexture = loadTexture("FirstScree.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

// bool Game::MediumScreen()
// {
// 	// Loading success flag
// 	bool success = true;
// 	screen = 5;
// 	gTexture = loadTexture("bg.jpg");
// 	if (gTexture == NULL)
// 	{
// 		printf("Unable to run due to error: %s\n", SDL_GetError());
// 		success = false;
// 	}
// 	return success;
// }

// bool Game::HardScreen()
// {
// 	// Loading success flag
// 	bool success = true;
// 	screen = 6;
// 	gTexture = loadTexture("bg.jpg");
// 	if (gTexture == NULL)
// 	{
// 		printf("Unable to run due to error: %s\n", SDL_GetError());
// 		success = false;
// 	}
// 	return success;
// }

// bool Game::EndScreen()
// {
// 	// Loading success flag
// 	bool success = true;
// 	screen = 7;
// 	gTexture = loadTexture("end.png");
// 	if (gTexture == NULL)
// 	{
// 		printf("Unable to run due to error: %s\n", SDL_GetError());
// 		success = false;
// 	}
// 	return success;
// }

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

	Finding_Nemo finding_nemo;

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				finding_nemo.createObject(xMouse, yMouse);
			}
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		finding_nemo.drawObjects();

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}

// void Game::run()
// {
// 	bool quit = false;
// 	SDL_Event e;
// 	// asteroids_point_zero apz;
// 	asteroids_point_zero *apz = new asteroids_point_zero();
// 	// if(screen == 1){
// 	// 	Mix_PlayMusic(gMusic, -2);
// 	// }

// 	while (!quit)
// 	{
// 		// Handle events on queue
// 		while (SDL_PollEvent(&e) != 0)
// 		{
// 			int xMouse, yMouse;
// 			// User requests quit
// 			if (e.type == SDL_QUIT)
// 			{
// 				quit = true;
// 			}
// 			if (e.type == SDL_MOUSEBUTTONDOWN)
// 			{
// 				// this is a good location to add pigeon in linked list.
// 				SDL_GetMouseState(&xMouse, &yMouse);
// 				if (xMouse > 175 && xMouse < 424 && yMouse > 355 && yMouse < 385)
// 				{
// 					LevelsScreen();
// 				}
// 				if (xMouse > 234 && xMouse < 367 && yMouse > 413 && yMouse < 448)
// 				{
// 					RulesScreen();
// 				}
// 				if (xMouse > 75 && xMouse < 193 && yMouse > 236 && yMouse < 264)
// 				{
// 					BackgroundScreen();
// 				}
// 				if (xMouse > 226 && xMouse < 400 && yMouse > 235 && yMouse < 266)
// 				{
// 					MediumScreen();
// 				}
// 				if (xMouse > 429 && xMouse < 549 && yMouse > 236 && yMouse < 263)
// 				{
// 					HardScreen();
// 				}
// 				if ((xMouse >= 258 && xMouse <= 347 && yMouse >= 480 && yMouse <= 503))
// 				{
// 					quit = true;
// 				}
// 			}
// 			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
// 			{
// 				if (screen == 2 || screen == 5 || screen == 6)
// 				{
// 					apz->create_bullets(xMouse + 28, yMouse);
// 				}
// 			}
// 			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && (screen == 2 || screen == 3 || screen == 4 || screen == 5 || screen == 6))
// 			{
// 				gTexture = loadTexture("Startingscreen.png");
// 				screen = 1;
// 			}
// 			if (e.type == SDL_MOUSEMOTION && screen == 2 || screen == 5 || screen == 6)
// 			{
// 				SDL_GetMouseState(&xMouse, &yMouse);
// 				// cout << xMouse << " " << yMouse;
// 				apz->checkMouseClick(xMouse, yMouse);
// 			}
// 			if (Mix_PlayingMusic() == 0)
// 			{
// 				// Play the music
// 				Mix_PlayMusic(gMusic, -1);
// 			}
// 		}

// 		SDL_RenderClear(Drawing::gRenderer);					  // removes everything from renderer
// 		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer
// 		//***********************draw the objects here********************
// 		if (apz->Life.n > 0)
// 		{
// 			if (screen == 2)
// 			{
// // 				apz->create_small_asteroid();
// // 				apz->create_ufo();
// // 				apz->create_bonus();
// // 				apz->create_fire();
// // 				apz->draw_spaceship();
// // 				apz->draw_small_asteroid();
// // 				apz->draw_ufo();
// // 				apz->draw_bonus();
// // 				apz->draw_fire();
// // 				apz->draw_bullets();
// // 				apz->collision();
// // 				apz->draw_heart();
// // 				apz->display_score();
// 				// apz->draw_Mid_Life();
// 				// apz->draw_End_Life();
// 			}
// 			if (screen == 5)
// 			{
// // 				apz->draw_medium();
// // 				apz->draw_tiny();
// // 				apz->draw_fire();
// // 				apz->create_ufo();
// // 				apz->create_bonus();
// // 				apz->draw_spaceship();
// // 				apz->create_medium();
// // 				apz->create_fire();
// // 				apz->create_tiny();
// // 				apz->draw_ufo();
// // 				apz->draw_bonus();
// // 				apz->draw_bullets();
// // 				apz->collision();
// // 				apz->draw_heart();
// // 				apz->display_score();
// 				// apz->draw_Mid_Life();
// 				// apz->draw_End_Life();
// 			}
// 			if (screen == 6)
// 			{
// 				apz->draw_hard();
// // 				apz->draw_fire();
// // 				apz->create_ufo();
// // 				apz->create_bonus();
// // 				apz->create_tiny();
// // 				apz->draw_spaceship();
// // 				apz->create_hard();
// // 				apz->create_fire();
// // 				apz->draw_bullets();
// // 				apz->draw_tiny();
// // 				apz->draw_bonus();
// // 				apz->draw_ufo();
// // 				apz->draw_heart();
// 				// apz->draw_Mid_Life();
// 				// apz->draw_End_Life();
// 				apz->collision();
// 				apz->display_score();
// 			}
// 		}
// 		else
// 		{
// 			EndScreen();
// 		}
// 		//****************************************************************
// 		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

// 		SDL_Delay(100); // causes sdl engine to delay for specified miliseconds
// 	}
// }

