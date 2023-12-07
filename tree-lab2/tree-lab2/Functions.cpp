#include "Functions.h"

void fill_from_file(BinaryTree* tree, int& error_code)
{
	fstream fs;
	fs.open("data.txt");

	if (!fs.is_open())
	{
		error_code = 1;
		return;
	}
	
	int temp;

	while (!fs.eof())
	{
		fs >> temp;
		if (fs.fail())
		{
			error_code = 2;
			fs.close();
			return;
		}
		if (temp < 0 || temp > 100)
		{
			error_code = 3;
			fs.close();
			return;
		}
	}
	fs.seekp(0, ios::beg);
	fs.close();
	fs.open("data.txt");

	while (!fs.eof())
	{
		fs >> temp;
		tree->insert(temp, error_code);
	}

	fs.close();
}


