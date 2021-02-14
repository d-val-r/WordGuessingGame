# ifndef GAMESTATE_H_
# define GAMESTATE_H_

class GameState
{
private:
	string _word_in_play;
	// the word to be guessed

	string _guessed;
	// output shown to user after every guess (ex. _ _ _ if no 
	// letters guessed right or c _ _ for correctly guessing the letter c)	

	string _letters_incorrectly_guessed;
	string _words_incorrectly_guessed;

	int _attempts_left;

public:
	GameState(){}
	
	GameState(string);
	// pre: the parameter will be the word the user needs to guess
	// post: saves the parameter to the _word_in_play data member
	// desc: sets the _attempts_left data member equal to the length of 
	//       the parameter	
	

	bool match(string);
	// pre:  the parameter is the word the user just guessed
	// post: returns true if the word guessed is correct 
	//       and decrements the number of attempts left and, if the guess
	//       was incorrect, also appends the word to words_incorrectly_guessed

	bool match(char);
	// pre: the parameter is the character the user just guessed
	// post: returns true if the character guessed is in the 
	//       _word_in_play data member and decrements attempts, and,
	//       if the guess was incorrect, also appends the character
	//       to _letters_incorrectly_guessed
	
	void setWord(string);
	// pre: the parameter is the word that needs to be guessed
	// post: sets _word_in_play to the argument provided
	// desc: will clear the _guessed, _words_incorrectly_guessed,
	//       and _letters_incorrectly_guessed variables to start a new 
	//       game without requiring a new GameState object to be instantiated

	void decrementAttempts();
	// pre: none
	// post: decrements _attempts_left by one	
	
	int getAttempts() const;
	// pre: none
	// post: returns _attempts_left 
	
	
	string getIncorrectLetters() const;
	// pre: none
	// post: returns _letters_incorrectly_guessed
	

	string getIncorrectWords() const;
	// pre: none
	// post: returns _words_incorrectly_guessed
	
	string getWinWord() const;
	// pre: none
	// post: returns _word_in_play 

	string getStatus() const;
	// pre: none
	// post: returns _guessed 

};


# endif
