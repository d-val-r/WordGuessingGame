/*
CSCE 306, Assignment 1
Dictionary headers, written by David Rudenya
*/


# ifndef DICTIONARY_H_
# define DICTOINARY_H_

class Dictionary
{
private:
	vector<string> _container;
public:
	Dictionary(){}
	
	void populateFromFile(ifstream&);
	// pre: expects a file to be provided
	// post: the _container vector will be populated with strings from a 
	//       provided file
	// desc: clears _container of any data before populating, and so
	//       can be used to repopulate with new values without 
	//       instantiating a new Dictionary object	
	
	void populate();
	// pre: none 
	// post: populates _container variable  with words entered by the user
	// desc: uses sentinel loop to gather user input and includes a 
	//       prompt so that programs using the object need not guess 
	//       what sentinel value to inform the user of 
	

	string access();
	// pre: expects the vector data member to have been populated by 
	//      either populate() or populateFromFile()
	// post: returns a randomly-chosen string from the vector data member
	//       or an empty string if the user never enters any values 
	
};

# endif
