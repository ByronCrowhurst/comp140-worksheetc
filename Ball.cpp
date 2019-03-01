#include "Ball.h"



Ball::Ball(int x, int y, int width, int height, int speed)
{
	ballX = x;
	ballY = y;
	ballW = width;
	ballH = height;
	ballSpeed = speed;
	SetRect();
	up = true;
	left = true;
}


Ball::~Ball()
{
	std::cout << "ball destroyed" << std::endl;
}

void Ball::MoveBall()
{
	if (up)
	{
		ballY -= ballSpeed;
	}
	else
	{
		ballY += ballSpeed;
	}

	if (left)
	{
		ballX -= ballSpeed;
	}
	else
	{
		ballX += ballSpeed;
	}
}

void Ball::SetRect()
{
	ballRect.x = ballX;
	ballRect.y = ballY;
	ballRect.w = ballW;
	ballRect.h = ballH;
}

int Ball::TopRightCollide()
{
	return ballRect.x + ballW;
}

int Ball::BottomRightCollide()
{
	return ballRect.x + ballW + ballH;
}


int Ball::BottomLeftCollide()
{
	return ballRect.y + ballH;
}

void Ball::TopScreenCollide(int screenH)
{
	if (ballRect.y <= 0)
	{
		up = false;
	}
}

void Ball::BottomScreenCollide(int screenH)
{
	if (this->BottomLeftCollide() >= screenH)
	{
		up = true;
	}
}

void Ball::LeftScreenCollide(int screenW)
{
	if (ballRect.x <= 0)
	{
		left = false;
	}
}

void Ball::RightScreenCollide(int screenW)
{
	if (this->TopRightCollide() >= screenW)
	{
		left = true;
	}
}

void Ball::HitPlayer(SDL_Rect playerSprite)
{

	if (ballRect.x <= playerSprite.x + playerSprite.w && ballRect.y <= playerSprite.y + playerSprite.w)
	{
		if (ballRect.x <= playerSprite.x && ballRect.y >= playerSprite.y)
		{
			if (left)
			{
				left = false;
			}
			else
			{
				left = true;
			}
		}

	}
}

SDL_Rect Ball::GetRect()
{
	this->SetRect();
	return ballRect;
}
