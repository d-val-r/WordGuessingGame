# ifndef GAMESTATE_H_
# define GAMESTATE_H_

class GameState
{
private:
	string _word_in_play;
	// the word to be guessed

	vector<char> _guessed;
	// output shown to user after every guess (ex. _ _ _ if no letters guessed right or
	// c _ _ for correctly guessing the letter c)	

	// current state of the user's guessed word? ask what that means

	vector<char> _letters_incorrectly_guessed;
	vector<string> _words_incorrectly_guessed;

	int _attempts_left;

public:
	GameState(){}
	// inline method
	
	GameState(string);
	// pre: the parameter will be the word the user needs to guess
	// post: saves the parameter to the _word_in_play data member
	// desc: sets the _attempts_left data member equal to the length of the parameter	
	

	bool match(string);
	// pre: assumes the GameState and Dictionary Objects have been instantiated. 
	//      Parameter is the word the user just guessed
	// post: returns true if the word guessed is correct and ends the game, or
	//       returns false if not and decrements the number of attempts left,
	//       adds to the words_incorrectly_guessed data member
	
	bool match(char);
	// pre: assumes the GameState and Dictionary Objects have been instantiated. 
	//      Parameter is the letter the user just guessed
	// post: returns true if the letter guessed is correct and ends the game, or
	//       returns false if not and decrements the number of attempts left,
	//       adds to the letters_incorrectly_guessed data member
	


};


# endif
