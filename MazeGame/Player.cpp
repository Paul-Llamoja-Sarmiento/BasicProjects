#include "Player.h"
#include <iostream>
#include <cctype>


Player::Player()
	: x {1} , y {1} , lastX{} , lastY{}
{
}


void Player::call_input()
{
	char userInput{};
	std::cout << "Enter your move command 'w' 'a' 's' 'd': " << std::endl;
	std::cin >> userInput;
	userInput = std::tolower(userInput);
	lastX = x;
	lastY = y;
	
	switch(userInput)
	{
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		case 's':
			y++;
			break;
		case 'w':
			y--;
			break;
		default:
			break;
	}
}


int Player::get_x()
{
  	return x;
}


int Player::get_y()
{
  	return y;
}


void Player::reset_position()
{
	x = 1;
	y = 1;
}


void Player::last_position()
{
	x = lastX;
	y = lastY;
}
