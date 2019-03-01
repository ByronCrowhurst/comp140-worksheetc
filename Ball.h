#pragma once
#include "stdafx.h"
#include <iostream>
#include "SDL.h"

class Ball
{
public:
	Ball(int x, int y, int width, int height, int speed);
	~Ball();
	void MoveBall();
	void SetRect();
	int TopRightCollide();
	int BottomRightCollide();
	int BottomLeftCollide();
	void TopScreenCollide(int screenH);
	void BottomScreenCollide(int screenH);
	void LeftScreenCollide(int screenW);
	void RightScreenCollide(int screenW);
	void HitPlayer(SDL_Rect playerSprite);
	SDL_Rect GetRect();
private:
	int ballX;
	int ballY;
	int ballW;
	int ballH;
	int ballSpeed;
	int ballMaxSpeed;
	bool up;
	bool left;
	SDL_Rect ballRect;
};

