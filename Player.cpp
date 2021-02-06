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

void Player::setWins(int w)
{
	_num_of_wins = w;
}


void Player::setLosses(int l)
{
	_num_of_losses = l;
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
