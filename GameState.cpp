# include <string>
# include <vector>
using namespace std;
# include "GameState.h"


GameState::GameState(string word)
{
	_word_in_play = word;
	_attempts_left = word.length();
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
	int hits = 0;
	for (int i = 0; i < _word_in_play.length(); i++)
	{
		if (_word_in_play[i] == guess) 
		{
			_guessed[i] = (char) guess;
			hits++;
		} 
	}
	if (hits == 0) 
	{
		_letters_incorrectly_guessed.push_back(guess);
		_attempts_left--;
		return false;
	} else
		return true;
}
