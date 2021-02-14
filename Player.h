/*
CSCE 306, Assignment 1
Player headers, written by David Rudenya
*/

# ifndef PLAYER_H_
# define PLAYER_H_


class Player
{
private:
	string _name;
	int _num_of_wins;
	int _num_of_losses;
public:
	Player()
	{
		_num_of_wins = 0;
		_num_of_wins = 0;
	}
	// pre: none
	// post: in-line method, sets values to zero so that incrementing
	//       methods below do not fail when calling ++ on what would have
	//       been null values
	
	Player(string);
	// pre: the parameter is for the player's name
	// post: instantiates a player object with name set to the parameter
	

	void setName(string);
	// pre: none
	// post: set _name data member to the argument
	

	void incrementWins();
	// pre: none 
	// post: adds 1 to _num_of_wins


	void incrementLosses();
	// pre: none 
	// post: adds 1 to _num_of_losses 
	

	string getName() const;
	// pre: none 
	// post: stores player name in the variable at the 
	//       source of the function call

	int getWins() const;
	// pre: none
	// post: stores the number of player wins in the 
	//       variable at the source of the function call
	
	int getLosses() const;
	// pre: none
	// post: stores the number of player loses in the variable at the 
	//       source of the function call
		
};


# endif
