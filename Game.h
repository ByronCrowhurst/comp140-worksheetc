#pragma once
#include "SDL.h"
#include <serial\serial.h>
#include "SerialInterface.h"
#include "Player.h"
#include "Ball.h"

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool initSerialConnection();
	bool running() { return isRunning; };

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRenderer;
	bool isRunning;
	int gameWidth;
	int gameHeight;
	const int speed = 7;
	SerialInterface* serial;
	Player* playerOne;
	Player* playerTwo;
	Ball* ball;
	SDL_Rect playerPosition;
};

