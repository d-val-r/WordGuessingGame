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
	_container.clear();	
	
	string usr_val;

	cout << "Please enter a word to add to the dictionary. ";
	cout << "Type 'qq' to finish entering." << endl;
	cout << "Enter a value: ";
	cin >> usr_val;

	while (usr_val != "qq")
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
