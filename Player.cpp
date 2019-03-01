#include "Player.h"



Player::Player(int y, int w, int h, int playerNum, int screenWidth, int screenHeight)
{
	// Initialise the player to either player 1 or player 2
	positionY = y;
	sizeW = w;
	sizeH = h;
	playerNum = playerNum;
	SetX(playerNum);
	screenW = screenWidth;
	screenH = screenHeight;
	SetRectangle(positionX, positionY, sizeW, sizeH);
	std::cout << "Player " << playerNum << " created" << std::endl;
}


Player::~Player()
{
	std::cout << "Player destroyed." << std::endl;
}

int Player::GetY()
{
	return positionY;
}

void Player::SetY(int y)
{

	positionY = positionY + y;
}

void Player::SetX(int controller)
{
	// There is a posibility of only two players
	switch (controller)
	{
	case 1:
		positionX = 100;
		break;
	case 2:
		positionX = 500;
		break;
	}
}

int Player::GetX()
{
	return positionX;
}
int Player::GetScore()
{
	return score;
}

void Player::AddToScore()
{
	score++;
}

void Player::SetRectangle(int x, int y, int w, int h)
{
	// Players Transform
	playerSprite.x = x;
	playerSprite.y = y;
	playerSprite.w = w;
	playerSprite.h = h;
}

SDL_Rect Player::GetRect()
{
	// std::cout << playerSprite.x << " " << playerSprite.y << std::endl;
	this->SetRectangle(positionX, positionY, sizeW, sizeH);
	return playerSprite;
}

int Player::GetHeight()
{
	return sizeH;
}

int Player::GetTopRight()
{
	// Since y is already top left corner, return top right corner
	return playerSprite.y + playerSprite.w;
}

int Player::GetBottomRight()
{
	// Top left corner plus width plus height to get bottom right corner
	return (playerSprite.y + playerSprite.w) + playerSprite.h;
}

int Player::GetBottomLeft()
{
	// Top left plus height to get bottom left
	return playerSprite.y + playerSprite.h;
}
