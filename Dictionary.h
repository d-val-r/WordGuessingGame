# ifndef DICTIONARY_H_
# define DICTOINARY_H_

class Dictionary
{
private:
	vector<string> _container;
public:
	Dictionary(){}
	// in-line method
	
	void populateFromFile();
	// pre: none
	// post: the _container vector will be populated with strings from a provided file
	// desc: prompts user to enter a file name and extension that the method then reads
	
	void populate();
	// pre: none 
	// post: populates the vector data member of the dictionary with words entered by the user
	// desc: populates the vector data member by using a sentinel loop to gather user's words 
	

	string access();
	// pre: expects the vector data member to have been populated by either populate() or populateFromFile()
	// post: returns a randomly-chosen string from the vector data member
	
};





# endif
