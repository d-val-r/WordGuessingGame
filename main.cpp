# include <iostream>
# include <vector>
# include <fstream>
using namespace std;
# include "Dictionary.h"
# include "Player.h"
# include "GameState.h"




void printProgress(string guess, string name, int attempts, string words, string characters)
{
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	cout << "\n\n";

	cout << name << ", you have " << attempts << " attempts left." << endl << endl;

	cout << "Words Incorrectly Guessed: "  << words << endl << endl;
	cout << "Letters Incorrectly Guessed: " << characters << endl << endl;
	
}


void printProgress(string guess)
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

		g.setWord(dict.access());


		won = false;
		printProgress(g.getStatus());	

		while (g.getAttempts() > 0 && !won 
				&& g.getStatus() != g.winWord())
		{
		
			cout << "Your guess: ";
			cin >> guess;
			g.decrementAttempts();
			if (guess.length() == 1)
			{
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

		
		if (g.getStatus() == g.winWord() || won)
		{
			p.incrementWins();
			cout << "Congratulations, " << p.getName()  <<  ", you win!" << endl;
			cout << "Wins" << "\t" << "Losses" << endl;
			cout << p.getWins() << "\t" << p.getLosses() << endl;
		} else if (g.getAttempts() == 0 && !won)
		{
			p.incrementLosses();
			cout << "Not quite! The word was " << g .winWord() << endl;
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
