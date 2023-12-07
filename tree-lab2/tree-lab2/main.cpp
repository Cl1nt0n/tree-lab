﻿#include <iostream>
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

	while (true)
	{
		print_menu();
		int command;
		while (!(cin >> command))
		{
			cout << "Неверная команда. " << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (command)
		{
		case 1:
		{
			int element;
			cout << "Введите элемент: ";

			while (!(cin >> element) || element > 100 || element < 0)
			{
				cout << "Ошибка! Элемент должен быть числом в диапазоне между [0,100]" << endl; 
				cin.clear();
				cin.ignore(10000, '\n');
			}

			tree->insert_element(element, error_code);
			switch (error_code)
			{
			case 0:
				cout << "Добавление произошло успешно !" << endl; 
				break;
			case 1:
				cout << "Ошибка! Элемент с таким значением уже существует!" << endl; 
				break;
			}
			break;
		}
		case 2:
		{
			int element;
			cout << "Введите элемент: ";
			cin >> element;

			int adress = tree->find_element(element);
			if (adress == -1)
				cout << "Элемент не найден!" << endl;
			else
				cout << "Элемент найден! Адрес элемента: " << adress << "\n";
			break;
			
		}
		case 3:
		{
			int element;
			cout << "Введите элемент: ";

			while (!(cin >> element) || element > 100 || element < 0)
			{
				cout << "Ошибка! Элемент должен быть числом в диапазоне между [0,100]" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			tree->remove_element(element, error_code);

			switch (error_code)
			{
			case 0:cout << "Удаление произошло успешно !\n"; break;
			case 1:cout << "Ошибка ! Элемент с таким значением не существует!\n"; break;
			}
			break;
			tree->print_tree(error_code);
			if (error_code == 1)
				cout << "Дерево не содержит узлов." << endl;
			break;
		}
		case 4:
		{
			tree->print_tree(error_code);
			if (error_code == 1)
				cout << "Дерево не содержит узлов." << endl;
			break;
		}
		case 5:
		{
			cout << "Высота дерева: " << tree->get_height() << '\n';
			break;
		}
		case 6:
		{
			cout << "Количество узлов дерева: " << tree->get_nodes_count() << '\n';
			break;
		}
		case 7:
		{

			cout << "Подсчёт суммы длин от корня до каждой из вершин,содержащей чётное число: " << sum(root, 0) << '\n';
			break;
		}
		default: 
			cout << "Команда не найдена\n"; 
			break;
		}
		cout << '\n';
	}
}

