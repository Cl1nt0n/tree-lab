#include <iostream>
#include "BinaryTree.h"
#include "Functions.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int error_code;//код ошибки
	BinaryTree* tree = new BinaryTree();//бинарное дерево
	fill_from_file(tree, error_code);

	switch (error_code)
	{
	case 1:
		cout << "Ошибка. Файл не найден." << endl;
		return 1;
	case 2:
		cout << "Ошибка. Неверные значения в файле." << endl;
		return 2;
	case 3:
		cout << "Ошибка. Неверные значения в файле." << endl;
		return 3;
	default:
		cout << "Данные успешно считаны." << endl;
		break;
	}
}
