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
	// in-line method, sets values to zero so that incrementing
	// methods below do not fail when calling ++ on null values
	
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
	// pre: assumes that the player object exists and has been given a name
	// post: stores player name in the variable at the 
	//       source of the function call

	int getWins() const;
	// pre: assumes that the player object exists and that the 
	//      number of wins is not null
	// post: stores the number of player wins in the 
	//       variable at the source of the function call
	
	int getLosses() const;
	// pre: assumes that the player object exists and that the number of 
	//      loses is not null
	// post: stores the number of player loses in the variable at the source of the function call
		
};


# endif
