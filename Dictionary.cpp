# include <vector>
# include <string>
using namespace std;
# include <iostream>
# include <fstream>
# include "Dictionary.h"



void Dictionary::populateFromFile(ifstream& file)
{

	_container.clear();

	string line;
	file >> line;

	while (!file.eof())
	{
		_container.push_back(line);
		file >> line;
	}
}



void Dictionary::populate()
{
	string usr_val;
	_container.clear();	

	cout << "Please enter a word to add to the dictionary. Type 'quit()' to finish entering." << endl;
	cout << "Enter a value: ";
	cin >> usr_val;

	while (usr_val != "quit()")
	{
		_container.push_back(usr_val);
		cout << "Enter a value: ";
		cin >> usr_val;
	}	
}


string Dictionary::access()
{
	string return_value = _container[rand() % _container.size()];
	return return_value;
}
