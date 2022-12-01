#include "game.hpp"
#include "drawing.hpp"
#include "FindingNemo.hpp"
#include <vector>
#include <time.h>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <ctime>
#include<string>
#include<SDL_ttf.h>
using namespace std;
using namespace std::chrono;

Game *Game::ptr = NULL;

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Renderer *Drawing::hRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;

static int screen;

Game::Game(){}
Game::~Game(){
	delete ptr;
}

// initialising a static pointer
Game* Game::getPointer(){
	if(ptr == NULL){
		ptr = new Game();
	}
	return ptr;
void Game::show_time(int t){
	TTF_Init(); //Initializes SDL_TTF for displaying text in 
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24); //Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0}; //This is the texts color that can be changed using RGB values from 0 to 255.
    string tmp = to_string(t); //converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color); //A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); //Converts into texture that can be displayed
    SDL_Rect Message_rect = {800, 30, 90, 30}; //create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}

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
				//initialising mixer 
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
//flag for hard screen loading
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

//flag for medium screen loading
bool Game::MediumScreen()
{
	// Loading success flag
	// auto start = high_resolution_clock::now();
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

//flag for easy screen loading
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

//flag for initial screen loading
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

//flag for Rules Screen loading
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

//flag for level screen loading
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

//flag for end screen loading
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

//flag for Winning screen loading
bool Game::WinningScreen()
{
	// Loading success flag
	bool success = true;
	screen = 8;
	gTexture = loadTexture("Winning Screen.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
} 

//flag for Riddle 1 screen loading
bool Game:: R1()
{
	// Loading success flag
	// string ans;
	bool success = true;
	gTexture = loadTexture("R1.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	SDL_Delay(10000);
	SDL_RenderPresent(Drawing::gRenderer);
	if(success == true)screen = 9;
	// cout << "Enter your answer: " << endl;
	// cin >> ans;
	// if (ans == "Pacific Ocean"){
	// 	fn->correct = true;
	// }
	cout << success << endl;
	return success;
} 
//flag for Riddle 2 screen loading
bool Game:: R2()
{
	// Loading success flag
	// string ans;
	bool success = true;
	gTexture = loadTexture("R2.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	SDL_Delay(10000);
	SDL_RenderPresent(Drawing::gRenderer);
	if(success == true)screen = 10;
	/* cout << "Enter your answer: " << endl;
	cin >> ans;
	if (ans == "Pacific Ocean"){
		fn->correct = true;
	} */
	cout << success << endl;
	return success;
} 
//flag for Riddle 3 screen loading
bool Game:: R3()
{
	// Loading success flag
	// string ans;
	bool success = true;
	gTexture = loadTexture("R3.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	SDL_RenderPresent(Drawing::gRenderer);
	SDL_Delay(10000);
	if(success == true)screen = 11;
	// cout << "Enter your answer: " << endl;
	// cin >> ans;
	// if (ans == "Pacific Ocean"){
	// 	fn->correct = true;
	// }
	cout << success << endl;
	return success;
} 
//flag for Riddle 4 screen loading
bool Game:: R4()
{
	// Loading success flag
	// string ans;
	bool success = true;
	gTexture = loadTexture("R4.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	SDL_RenderPresent(Drawing::gRenderer);
	SDL_Delay(10000);
	if(success == true)screen = 12;
	// cout << "Enter your answer: " << endl;
	// cin >> ans;
	// if (ans == "Pacific Ocean"){
	// 	fn->correct = true;
	// }
	cout << success << endl;
	return success;
} 
//flag for Riddle 5 screen loading
bool Game:: R5()
{
	// Loading success flag
	// string ans;
	bool success = true;
	gTexture = loadTexture("R5.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	SDL_RenderPresent(Drawing::gRenderer);
	SDL_Delay(10000);
	if(success == true)screen = 13;
	/* cout << "Enter your answer: " << endl;
	cin >> ans;
	if (ans == "Pacific Ocean"){
		fn->correct = true;
	} */
	cout << success << endl;
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
	// Timer *time = new Timer();
	// time->Start();
	// time->show_time();
	// int time_left = 180;
	auto start = high_resolution_clock::now();
	// Finding_Nemo fn;
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

			// to click play, rules, quit, hard screen, medium screen, easy screen
			if(e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if (xMouse > 401 && xMouse < 498 && yMouse > 368 && yMouse < 423 && screen == 1)
				{
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
					// auto start = high_resolution_clock::now();
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
			// returning to main screen once escape is pressed
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && (screen == 2 || screen == 3 || screen == 4 || screen == 6 || screen == 7 || screen == 10))
			{
				gTexture = loadTexture("FirstScreen.png");
				screen = 1;
			}
			// returns to playscreen on enter after data entry
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_RETURN && (screen == 9 || screen == 10 || screen == 11 || screen == 12 || screen == 13))
			{
				cout << "ENTER key presses"	<< endl;
				fn->riddle = false;
				fn->paused = false;
				HardScreen();
			}

			// to pause and unpause the screen
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
			// to move Dory with the cursor
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
		// if (fn->Life.life > 0 && fn->paused == false && fn->riddle == false)
		if (fn->Life.life > 0 && fn->paused == false)
		{
			// Hard Level
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
				fn->create_bonusfish();
				fn->draw_Shark1();
				fn->draw_Shark2();
				fn->draw_lives();
				fn->draw_bonusfish();
				fn->show_score();
				fn->text_score();
				fn->collision_dhuzzz();
				/* if (fn->riddle == true){
					int riddle_screen[5] = {9, 10, 11, 12, 13};
        			int sc = riddle_screen[rand() % 5]; 
					if (sc == 9){gTexture = loadTexture("R1.png"); screen = 9;fn->riddle == false;}
					else if (sc == 10){gTexture = loadTexture("R2.png");screen =10;fn->riddle == false;}
					else if (sc == 11){gTexture = loadTexture("R3.png");screen =11;fn->riddle == false;}
					else if (sc == 12){gTexture = loadTexture("R4.png");screen =12;fn->riddle == false;}
					else if (sc == 13){gTexture = loadTexture("R5.png");screen =13;fn->riddle == false;}
				}   */
				fn->delete_Objects();
				// time->Start();
				// time->show_time();
				// time->Start();
				// time->show_time();
				// fn->timer();
				// fn->start_time();
				// fn->show_time();
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);
				// time_left = time_left - duration.count();
				cout << "time: " << duration.count() << endl;
				/* if (fn->get_score() >= 100 && duration.count() <=100)
					{
						WinningScreen();
					}
					else if (fn->get_score() <= 100 && duration.count() >= 100)
					{
						EndScreen();
				} */
				int t = 185 - duration.count();
				cout << "You have " << t << " seconds left\n";
				show_time(t);
		// 		if (SDL_Delay(180000))
		// `		{
		// 			cout << "Game end!!!" << endl;
		// 		}
				// auto stop = high_resolution_clock::now();
				// auto duration = duration_cast<seconds>(stop - start);
				// cout << "time: " << duration.count() << endl;
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
				fn->create_bonusfish();
				fn->draw_Shark1();
				fn->draw_Shark2();
				fn->draw_lives();
				fn->draw_bonusfish();
				fn->show_score();
				fn->text_score();
				fn->collision_dhuzzz();
				/* if (fn->riddle == true){
					int riddle_screen[5] = {9, 10, 11, 12, 13};
        			int sc = riddle_screen[rand() % 5]; 
					if (sc == 9)R1();
					else if (sc == 10)R2();
					else if (sc == 11)R3();
					else if (sc == 12)R4();
					else if (sc == 13)R5();
				} */
				fn->delete_Objects();
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);
				cout << "time: " << duration.count() << endl;
				/* if (fn->get_score() >= 100 && duration.count() <=100)
				{
					WinningScreen();
				}
				else if (fn->get_score() <= 100 && duration.count() >= 100)
				{
					EndScreen();
				} */
				int t = 185 - duration.count();
				cout << "You have " << t << " seconds left\n";
				show_time(t);
		// 		if (SDL_Delay(180000))
		// `		{
		// 			cout << "Game end!!!" << endl;
		// 		}
				// auto stop = high_resolution_clock::now();
				// auto duration = duration_cast<seconds>(stop - start);
				// cout << "time: " << duration.count() << endl;
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
				fn->create_Shark2_Easy();
				fn->create_bonusfish();
				fn->draw_Shark1();
				fn->draw_Shark2();
				fn->draw_lives();
				fn->draw_bonusfish();
				fn->show_score();
				fn->text_score();
				fn->collision_dhuzzz();
				/* if (fn->riddle == true){
					int riddle_screen[5] = {9, 10, 11, 12, 13};
        			int sc = riddle_screen[rand() % 5]; 
					if (sc == 9)R1();
					else if (sc == 10)R2();
					else if (sc == 11)R3();
					else if (sc == 12)R4();
					else if (sc == 13)R5();
				} */
				fn->delete_Objects();
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);
				cout << "time: " << duration.count() << endl;
				/* if (fn->get_score() >= 100 && duration.count() <=100)
				{
					WinningScreen();
				}
				else if (fn->get_score() <= 100 && duration.count() >= 100)
				{
					EndScreen();
				} */
		
				int t = 185 - duration.count();
				cout << "You have " << t << " seconds left\n";
				show_time(t);
		// 		if (SDL_Delay(180000))
		// `		{
		// 			cout << "Game end!!!" << endl;
		// 		}
				// auto stop = high_resolution_clock::now();
				// auto duration = duration_cast<seconds>(stop - start);
				// cout << "time: " << duration.count() << endl;
			}
			/* if (screen == 9 || screen == 10 || screen == 11 || screen == 12 || screen == 13){
				string ans;
				cout << "Enter your answer: " << endl;
				getline (cin, ans);
				if (ans == "Pacific Ocean" && screen == 9)fn->correct = true;
				else if (ans == "selfish" && screen == 10)fn->correct = true;
				else if (ans == "nobody" && screen == 11)fn->correct = true;
				else if (ans == "Sunfish" && screen == 12)fn->correct = true;
				else if (ans == "Dolphin" && screen == 13)fn->correct = true;
			} */
		}
		else 
		{	// losing screen
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




