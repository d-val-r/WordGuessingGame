/*
CSCE 306, Assignment 1
Main file of Assignment 1, written by David Rudenya
*/


# include <iostream>
# include <vector>
# include <fstream>
using namespace std;
# include "Dictionary.h"
# include "Player.h"
# include "GameState.h"



void printProgress(GameState& g, string name) 
// pre: parameters are a GameState object and a name to refer to the player by 
// post: no changes to variables 
// desc: gets data from the GameState object and formats and prints 
//       out the number of attempts, the state of the word to be guessed, 
//       as well as the list of words/letters user 
//       incorrectly guessed
	
{
	
	string guess = g.getStatus();
	int attempts = g.getAttempts();
	string words = g.getIncorrectWords();
	string characters = g.getIncorrectLetters();


	// prints out space-delimited status of the state of the guessed word
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	
	cout << "\n\n";

	cout << name << ", you have " << attempts << " attempts left." << endl << endl;

	cout << "Words Incorrectly Guessed: "  << words << endl << endl;
	cout << "Letters Incorrectly Guessed: " << characters << endl << endl;
}


void printProgress(string guess) 
// pre: parameter is the current status of the guessed word
// post: no changes to variables
// desc: overloaded function, formats and prints only the status of the 
//       user's guessed word 
{
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	cout << "\n\n";
}



void printWin(Player& p) 
// pre: parameter is a reference to a Player object
// post: no changes to variables
// desc: gathers relevant user data and formats/prints it 
//       after a user wins a round
{
	cout << "Congratulations, " << p.getName()  <<  ", you win!" << endl;
	cout << "Wins" << "\t" << "Losses" << endl;
	cout << p.getWins() << "\t" << p.getLosses() << endl;
	cout << "\n\n";	
}

void printLoss(Player& p, string win_word) 
// pre: parameter is a reference to a Player object and the word to be guessed
// post: no changes to variables
// desc: gathers relevant user data and formats/prints it after a user
//       loses a round
{
	cout << "Not quite! The word was " << win_word << endl;
	cout << "Wins" << "\t" << "Losses" << endl;
	cout << p.getWins() << "\t" << p.getLosses() << endl << endl;
}

int main()
{
	Dictionary dict;

	cout << "Please enter a username to play: ";

	string name;
	cin >> name;
	Player p(name);
	


	bool won;

	// user's choice of how to select words (or quit)
	int choice;

	string guess;
	string file_name;

	GameState g;


	cout << "To start the game, enter either 1 to enter words to guess ";
	cout << "or 2 to provide a file to read words from. ";
        cout <<	"Enter 0 to quit." << endl;

	cin >> choice;

	while (choice != 0)
	{

		if (choice == 1)
			dict.populate();
		
		else
		{
			cout << "Please enter the name of the file with the extension: ";
			cin >> file_name;
			ifstream file(file_name);

			if (!file)
			{
				cout << "error opening file" << endl;
				exit(-1);
			}
			
			dict.populateFromFile(file);
		}	
			
		string win_word = dict.access();	

		if (win_word != "")
		{
		
			won = false;
			g.setWord(win_word);	

			// prints dashes to represent length of the word
			printProgress(g.getStatus());	

			// loop continues while attempts are not exhausted, the user
			// has not guessed the right word, and while the characters
			// guessed do not spell out the correct word
			while (g.getAttempts() > 0 && !won 
					&& g.getStatus() != win_word)
			{
			
				cout << "Guess a word or a letter: ";
				cin >> guess;
				cout << "\n\n";
				g.decrementAttempts();
				if (guess.length() == 1)
				{
					// user has entered a character, not a word,
					// so get the first (and only) character of 
					// the string with indexing, which returns a char
					g.match(guess[0]);	
					printProgress(g, p.getName());
				}
				else if (g.match(guess))
					// user has entered a string and guessed 
					// correctly
				{
					won = true;
				} else
				{	
					// user has entered a string and guessed
					// incorrectly
					printProgress(g, p.getName());
				}
				
			}

			// checks if the above loop exited due to a win condition,
			// as opposed to the user running out of attempts
			if (g.getStatus() == win_word || won)
			{
				p.incrementWins();
				printWin(p);
			} else if (g.getAttempts() == 0)
			{
				p.incrementLosses();
				printLoss(p, win_word);
			}

		}	

		cout << "To play again, enter either 1 to enter words ";
		cout << "to guess or 2 to read words from a file." << endl;
		cout << "Enter 0 to quit the game." << endl;
		cin >> choice;
			
	}
	return 0;
}
