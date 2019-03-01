#pragma once
#include "stdafx.h"
#include <iostream>
#include "SDL.h"

class Player
{
public:
	Player(int y, int w, int h, int playerNum, int screenWidth, int screenHeight);
	~Player();
	int GetY();
	void SetY(int y);
	int GetX();
	void SetX(int controller);
	int GetHeight();
	int GetTopRight();
	int GetBottomRight();
	int GetBottomLeft();
	int GetScore();
	void AddToScore();
	void SetRectangle(int x, int y, int w, int h);
	SDL_Rect GetRect();
protected:

private:
	// Transform values
	int positionX;
	int positionY;
	int sizeW;
	int sizeH;
	int screenW;
	int screenH;
	// Do I need a player num to be stored???????
	int playerNum;
	SDL_Rect playerSprite;
	// Scoring system
	int score;
};

