# include <iostream>
# include <vector>
using namespace std;
# include "Dictionary.h"
# include "Player.h"
# include "GameState.h"




void printProgress(string guess, string name, int attempts)
{
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	cout << "\n";

	cout << name << ", you have " << attempts << " attempts left." << endl;

	cout << "Letters Incorrectly Guessed" << "\t" << "Words Incorrectly Guessed" << endl;

}


void printProgress(string guess)
{
	for (int i = 0; i < guess.length(); i++)
		cout << guess[i] << " ";
	cout << "\n";
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
			dict.populateFromFile();

		g.setWord(dict.access());


		won = false;
		printProgress(g.getStatus());	

		while (g.getAttempts() > 0 && !won 
				&& g.getStatus() != g.winWord())
		{
		
			cout << "Take a guess: ";
			cin >> guess;
			g.decrementAttempts();
			if (guess.length() == 1)
			{
				g.match(guess[0]);	
				printProgress(g.getStatus(), p.getName(), g.getAttempts());	
			}
			else if (g.match(guess))
			{
				cout << "you win!!!" << endl;
				won = true;
			}

			
		}

		
		if (g.getStatus() == g.winWord())
		{
			// placeholder message
			cout << "you win!" << endl;
		} else if (g.getAttempts() == 0 && !won)
		{
			// placeholder message
			cout << "Loser" << endl;
			cout << g.winWord() << endl;
		}


		cout << "To play again, enter either 1 to enter words ";
		cout << "to guess or 2 to read words from a file." << endl;
		cout << "Enter 0 to quit the game." << endl;
		cin >> choice;
	}	

	return 0;
}
