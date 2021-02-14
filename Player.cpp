/*
CSCE 306, Assignment 1
Player class, written by David Rudenya
*/

# include <string>
using namespace std;
# include "Player.h"

Player::Player(string name)
{
	_name = name;
}

void Player::setName(string name)
{
	_name = name;
}

void Player::incrementWins()
{
	_num_of_wins++;
}


void Player::incrementLosses()
{
	_num_of_losses++;
}


string Player::getName() const
{
	return _name;
}

int Player::getWins() const
{
	return _num_of_wins;
}


int Player::getLosses() const
{
	return _num_of_losses;
}
