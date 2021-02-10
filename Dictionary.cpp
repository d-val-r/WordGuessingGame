# include <vector>
# include <string>
using namespace std;
# include <iostream>
# include <fstream>
# include "Dictionary.h"



void Dictionary::populateFromFile()
{
	string file_name;
	cout << "Please enter the name of the file with the extension: ";
	cin >> file_name;
	ifstream file(file_name);

	if (!file)
	{
		cout << "error opening file" << endl;
		exit(-1);
	}

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

	cout << "Please enter a word to add to the dictionary. Type 'quit()' to finish entering." << endl;
	// update this opening message before launching
	
	_container.clear();	
	
	cin >> usr_val;
	while (usr_val != "quit()")
	{
		_container.push_back(usr_val);
		cout << "Enter another value: ";
		cin >> usr_val;
	}	
}


string Dictionary::access()
{
	string return_value = _container[rand() % _container.size()];
	return return_value;
}
