# include <vector>
# include <string>
using namespace std;
# include <fstream>
# include "Dictionary.h"



void Dictionary::populateFromFile(ifstream& file)
{
	string line;
	file >> line;

	while (!file.eof())
	{
		_container.push_back(line);
		file >> line;
	}
}



void Dictionary::populate(vector<string> v)
{
	_container = v;	
}


string Dictionary::access()
{
	string return_value = _container[rand() % _container.size()];
	return return_value;
}
