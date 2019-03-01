#include "stdafx.h"
#include "Game.h"
#include <iostream>

using std::cout;

/*
* Constructor - not used in this case
*
*/
Game::Game()
{
	
}

/*
	Decontructor - also not used in this case
*/
Game::~Game()
{
}

bool Game::initSerialConnection()
{
	serial = new SerialInterface();
	return true;
}
/*
* init - used to initialise and setup SDL
* Return true if everything is successful
*/
bool Game::init(const char * title, int xpos, int ypos, int width, int height, int flags)
{
	// initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SDL init success \n";

		// Create a window
		mainWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// if window succesful..
		if (mainWindow != 0) {
			cout << "Window creation success \n";

			// create renderer
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);

			// if renderer successful...
			if (mainRenderer != 0) {
				cout << "Renderer creation success \n";
				SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
			}
			else {
				cout << "renderer failed \n";
				return false;
			}
		}
		else {
			cout << "window failed \n";
			return false;
		}

	}
	else {
		cout << "SDL fail \n";
		return false;
	}

	isRunning = true;
	cout << "SDL init success \n";

	initSerialConnection();
	gameWidth = width;
	gameHeight = height;
	playerOne = new Player(100, 25, 100, 1, gameWidth, gameHeight);
	playerTwo = new Player(100, 25, 100, 2, gameWidth, gameHeight);
	ball = new Ball((gameWidth / 2), (gameHeight / 2), 25, 25, 3);
	return true;
}

void Game::render()
{
	// set background color
	SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
	
	// clear previous frame
	SDL_RenderClear(mainRenderer);

	// draw to the screen here!
	SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mainRenderer,&playerOne->GetRect());
	SDL_RenderFillRect(mainRenderer, &playerTwo->GetRect());
	SDL_RenderFillRect(mainRenderer, &ball->GetRect());

	// render new frame
	SDL_RenderPresent(mainRenderer);
}

/*
* update - Process all variables !in charge of anything to do with rendering
*
*/
void Game::update()
{
	serial->getPositions();
	playerOne->SetY(serial->getPot1());
	playerTwo->SetY(serial->getPot2());
	ball->MoveBall();
	ball->TopScreenCollide(gameHeight);
	ball->BottomScreenCollide(gameHeight);
	ball->LeftScreenCollide(gameWidth);
	ball->RightScreenCollide(gameWidth);
	ball->HitPlayer(playerOne->GetRect());
	//ball->HitPlayer(playerTwo->GetRect());
}

/*
* handleEvents - Poll Events and uses switch case to process specific events
*
*/
void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_w)
			{
				if (playerOne->GetY() >= gameHeight - gameHeight + speed)
				{
					playerOne->SetY(-speed);
				}
			}
			else if (event.key.keysym.sym == SDLK_s)
			{
				if (playerOne->GetBottomLeft() <= gameHeight - speed)
				{
					playerOne->SetY(speed);
				}
			}
			if (event.key.keysym.sym == SDLK_UP)
			{
				if (playerTwo->GetY() >= gameHeight - gameHeight + speed)
				{
					playerTwo->SetY(-speed);
				}
			}
			else if (event.key.keysym.sym == SDLK_DOWN)
			{
				if (playerTwo->GetBottomLeft() <= gameHeight - speed)
				{
					playerTwo->SetY(speed);
				}
			}
			break;
		default:
			break;
		}

	}
}

/*
* clean - Clean up SDL and close the port
*
*/
void Game::clean()
{	
	playerOne->~Player();
	playerTwo->~Player();
	ball->~Ball();
	cout << "Cleaning SDL \n";
	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(mainRenderer);
	SDL_Quit();
}


