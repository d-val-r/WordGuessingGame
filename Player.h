# ifndef PLAYER_H_
# define PLAYER_H_


class Player
{
private:
	string _name;
	int _num_of_wins;
	int _num_of_losses;
public:
	Player(){}
	// pre: expects no argumets and assumes nothing about other objects
	// post: instantiates Player object with default C++ values 
	// inline method
	
	Player(string);
	// pre: the parameter is for the player's name
	// post: instantiates a player object with name set to the parameter
	

	void setName(string);
	// pre: assumes only that the player object exists and that a valid string argument was entered
	// post: _name data member changed to match argument
	

	void setWins(int);
	// pre: assumes only that the player object exists and that an int argument was entered
	// post: sets the _number_of_wins data member to match the given argument 


	void setLosses(int);
	// pre: assumes only that the player object exists and that an int argument was entered
	// post: sets the _number_of_loses data member to match the given argument
	

	string getName() const;
	// pre: assumes that the player object exists and has been given a name
	// post: stores player name in the variable at the source of the function call

	int getWins() const;
	// pre: assumes that the player object exists and that the number of wins is not null
	// post: stores the number of player wins in the variable at the source of the function call
	
	int getLosses() const;
	// pre: assumes that the player object exists and that the number of loses is not null
	// post: stores the number of player loses in the variable at the source of the function call
		
};


# endif
