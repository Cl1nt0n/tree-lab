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
		tree->insert_element(temp, error_code);
	}

	fs.close();
}

void print_menu()
{
	cout << "Нажмите: " << endl;
	cout << "1. Вставка узла" << endl;
	cout << "2. Поиск узла" << endl;
	cout << "3. Удаление узла" << endl; 
	cout << "4. Вывод дерева" << endl;
	cout << "5. Найти высоту дерева" << endl;
	cout << "6. Количество узлов" << endl;
	cout << "7. Определить сумму четных чисел" << endl;
	cout << "0. Выход" << endl;
}


