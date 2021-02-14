/*
CSCE 306, Assignment 1
Dictionary class, written by David Rudenya
*/

# include <vector>
# include <string>
using namespace std;
# include <iostream>
# include <fstream>
# include "Dictionary.h"



void Dictionary::populateFromFile(ifstream& file)
{

	_container.clear();
	// ensures no words present in _container

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
	// ensure no words present in _container
	
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
	string return_value = "";
	if (_container.size() != 0)	
		return_value = _container[rand() % _container.size()];
	return return_value;
}
