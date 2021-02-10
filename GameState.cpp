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
		_guessed.push_back("_");

}


bool GameState::match(string guess)
{
	if (guess == _word_in_play)
		return true;

	_attempts_left--;
	_words_incorrectly_guessed.push_back(guess);
	return false;
}



bool GameState::match(char guess)
{

	// make sure to check, either here or in main, if the player still has attempts left
	_attempts_left--;
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
		_letters_incorrectly_guessed.push_back(guess);
		return false;
	} else
		return true;
}



void GameState::setWord(string word)
{
	_guessed.clear();
	_letters_incorrectly_guessed.clear();
	_words_incorrectly_guessed.clear();


	_word_in_play = word;
	_attempts_left = word.length();
	for (int i = 0; i < word.length(); i++)
		_guessed.push_back("_");

}



int GameState::getAttempts() const
{
	return _attempts_left;
}





string GameState::output() const 
{
	string retVal = "";

	for (int i = 0; i < _guessed.size(); i++)
		 cout <<  _guessed[i] << " ";
	
	cout << "\n";
	return retVal;	
	
}
