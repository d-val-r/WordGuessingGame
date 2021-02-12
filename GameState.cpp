# include <iostream>
# include <string>
# include <vector>
using namespace std;
# include "GameState.h"


GameState::GameState(string word)
{
	_word_in_play = word;
	_attempts_left = word.length();
	for (int i = 0; i < word.length(); i++)
		_guessed += "_";
}


bool GameState::match(string guess)
{
	if (guess == _word_in_play)
		return true;

	_words_incorrectly_guessed += guess;
	_words_incorrectly_guessed += " ";
	return false;
}



bool GameState::match(char guess)
{

	// make sure to check, either here or in main, if the player still has attempts left
	int hits = 0;
		
	for (int i = 0; i < _word_in_play.length(); i++)
	{
		if (guess == _word_in_play[i])
		{
			_guessed[i] = guess;
			hits++;
		} 
	}


	if (hits == 0) 
	{
		_letters_incorrectly_guessed += guess;
		_letters_incorrectly_guessed += " ";
		return false;
	} else
		return true;
}



void GameState::setWord(string word)
{
	_guessed = "";
	_letters_incorrectly_guessed.clear();
	_words_incorrectly_guessed.clear();


	_word_in_play = word;
	_attempts_left = word.length();
	for (int i = 0; i < word.length(); i++)
		_guessed += "_";

}


void GameState::decrementAttempts()
{
	_attempts_left--;
}




int GameState::getAttempts() const
{
	return _attempts_left;
}





string GameState::output() const 
{
	string retVal = "";

	for (int i = 0; i < _guessed.length(); i++)
	{	retVal += _guessed[i]; 
		retVal += " ";
	}
	return retVal;	
	
}



string GameState::getStatus() const
{
	string retVal = _guessed.substr(0, _guessed.length() - 1);
	return _guessed; 
}

string GameState::winWord() const
{
	return _word_in_play;
}



string GameState::getIncorrectWords() const
{
	return _words_incorrectly_guessed;
}


string GameState::getIncorrectLetters() const
{
	return _letters_incorrectly_guessed;
}
