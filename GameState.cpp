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
	// stores dashes in the _guessed variable that will
	// be replaced by correclty guessed letters
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

	int hits = 0;
	

	// loop to find all instances of the guessed character in
	// _word_in_play
	
	for (int i = 0; i < _word_in_play.length(); i++)
	{
		if (guess == _word_in_play[i])
		{
			_guessed[i] = guess;
			hits++;
		} 
	}

	// if the letter never occured in the word
	if (hits == 0) 
	{
		_letters_incorrectly_guessed += guess;

		_letters_incorrectly_guessed += " ";
		// separates words with a space

		return false;
	} else
		return true;
}



void GameState::setWord(string word)
{
	_guessed = "";
	_letters_incorrectly_guessed = "";
	_words_incorrectly_guessed = "";


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


string GameState::getStatus() const
{
	string retVal = _guessed;

	return _guessed; 
}

string GameState::getWinWord() const
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
