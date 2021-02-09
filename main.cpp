# include <iostream>
# include <vector>
using namespace std;
# include "Dictionary.h"
# include "Player.h"
# include "GameState.h"

int main()
{
	Dictionary d;
	d.populateFromFile();
	GameState g(d.access());
	Player p("David");
	string guess;
	cout << "Enter a guess: ";
	cin >> guess;
	cout << g.match(guess) << endl;
	return 0;
}
