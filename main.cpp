# include <iostream>
# include <vector>
using namespace std;
# include "Dictionary.h"
# include "Player.h"
# include "GameState.h"

int main()
{
	Dictionary dict;

	cout << "Please enter a username to play: ";

	string name;
	cin >> name;
	Player p(name);
	


	int choice;
	string guess;

	GameState g;


	cout << "To start the game, enter either 1 to enter words to guess ";
	cout << "or 2 to provide a file to read words from. Enter 0 to quit." << endl;

	cin >> choice;

	while (choice != 0)
	{
		if (choice == 1)
			dict.populate();
		else
			dict.populateFromFile();

		g.setWord(dict.access());


		cout << "Take a guess: ";
		cin >> guess;

		if (guess.length() == 1)
		{
			g.match(guess[0]);	
			g.output();
		}
		else
		{

			if (g.match(guess))
			{
				cout << "you win!!!" << endl;
			}
		}


		cout << "To play again, enter either 1 to enter words to guess or 2 to read words from a file." << endl;
		cout << "Enter 0 to quit the game." << endl;
		cin >> choice;
	}	

	return 0;
}
