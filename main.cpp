# include <iostream>
# include <vector>
# include <fstream>
using namespace std;
# include "Dictionary.h"
# include "Player.h"
# include "GameState.h"




void printProgress(string guess, string name, int attempts, string words, string characters)
// pre: expects parameters
// post: formats and prints out the number of attempts as well as the
//       list of words/letters user incorrectly guessed
{
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	cout << "\n\n";

	cout << name << ", you have " << attempts << " attempts left." << endl << endl;

	cout << "Words Incorrectly Guessed: "  << words << endl << endl;
	cout << "Letters Incorrectly Guessed: " << characters << endl << endl;
}


void printProgress(string guess)
// pre: parameter is the current status of the guessed word
// post: formats and prints out the status of the guessed word
{
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	cout << "\n\n";
}


int main()
{
	Dictionary dict;

	cout << "Please enter a username to play: ";

	string name;
	cin >> name;
	Player p(name);
	


	bool won;
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

		// sets a word for the user to guess
		g.setWord(dict.access());
		

		won = false;


		// prints dashes to represent length of the word
		printProgress(g.getStatus());	

		// loop continues while attempts are not exhausted, the user
		// has not guessed the right word, and while the characters
		// guessed do not spell out the correct word
		while (g.getAttempts() > 0 && !won 
				&& g.getStatus() != g.getWinWord())
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
				printProgress(g.getStatus(), p.getName(), g.getAttempts(), g.getIncorrectWords(), g.getIncorrectLetters());
			}
			else if (g.match(guess))
			{
				won = true;
			} else
			{	
				printProgress(g.getStatus(), p.getName(), g.getAttempts(), g.getIncorrectWords(), g.getIncorrectLetters());
			}
			
		}

		// checks if the above loop exited due to a win condition,
		// as opposed to the user running out of attempts
		if (g.getStatus() == g.getWinWord() || won)
		{
			p.incrementWins();
			cout << "Congratulations, " << p.getName()  <<  ", you win!" << endl;
			cout << "Wins" << "\t" << "Losses" << endl;
			cout << p.getWins() << "\t" << p.getLosses() << endl;
			cout << "\n\n";	
		} else if (g.getAttempts() == 0 && !won)
		{
			p.incrementLosses();
			cout << "Not quite! The word was " << g.getWinWord() << endl;
			cout << "Wins" << "\t" << "Losses" << endl;
			cout << p.getWins() << "\t" << p.getLosses() << endl << endl;

		}


		cout << "To play again, enter either 1 to enter words ";
		cout << "to guess or 2 to read words from a file." << endl;
		cout << "Enter 0 to quit the game." << endl;
		cin >> choice;
	}	

	return 0;
}
