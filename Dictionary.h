# ifndef DICTIONARY_H_
# define DICTOINARY_H_

class Dictionary
{
private:
	vector<string> _container;
public:
	Dictionary(){}
	// in-line method

	void populateFromFile(ifstream&);
	// pre: the parameter is expected to be a file object already populated with string values separated by white-space characters
	// post: only adjusts pointer in the file to match where reading stopped, populates vector member variable of dictionary with
	//       string values read from the file
	// desc: will read all values from the file and store them in the vector data member of the dictionary

	
	void populate(vector<string>);
	// pre: takes as a parameter a vector of strings gathered from user's console input
	// post: populates the vector data member of the dictionary with words entered by the user
	// desc: populates the vector data member by setting it equal to the vector passed in
	

	string access();
	// pre: expects the vector data member to have been populated by either populate() or populateFromFile()
	// post: returns a randomly-chosen string from the vector data member
	
};





# endif
