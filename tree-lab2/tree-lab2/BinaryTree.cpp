#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::~BinaryTree()
{
	delete_tree(root);
}

void BinaryTree::insert_element(int value, int& error_code)
{
	if (root == nullptr)
	{
		root = new Node(value);
		root->value = value;
		return;
	}
	Node* current = root;
	Node* previous = current;

	while (current != nullptr)
	{
		previous = current;
		if (value == current->value)
		{
			error_code = 1;
			return;
		}
		value < current->value ? current = current->left : current = current->right;
	}

	Node* leaf = new Node(value);
	value < previous->value ? previous->left = leaf : previous->right = leaf;
	error_code = 0;
}

void BinaryTree::remove_element(int value, int& error_code)
{
	if (root == nullptr)
	{
		error_code = 1;
		return;
	}
	Node* current = root;
	Node* previous = current;

	while (current != nullptr && value != current->value)
	{
		previous = current;
		value < current->value ? current = current->left : current = current->right;
	}

	Node* removed = current;
	if (current != nullptr)
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			current->value < previous->value ? previous->left = nullptr : previous->right = nullptr;
		}
		else if (current->left == nullptr)
		{
			current->value < previous->value ? previous->left = current->right : previous->right = current->right;
		}
		else if (current->right == nullptr)
		{
			current->value < previous->value ? previous->left = current->left : previous->right = current->left;
		}
		else
		{
			Node* mostLeft = current->right;
			Node* mostLeftParent = current;

			while (mostLeft->left != nullptr)
			{
				mostLeftParent = mostLeft;
				mostLeft = mostLeft->left;
			}

			current->value = mostLeft->value;
			removed = mostLeft;

			if (mostLeftParent->left == mostLeft)
				mostLeftParent->left = nullptr;
			else
				mostLeftParent->right = mostLeft->right;
		}

		delete removed;

		error_code = 0;
	}
	else
	{
		error_code = 2;
	}
}

void BinaryTree::find_element(int value)
{
	Node* current = root;

	while (current != nullptr)
	{
		if (current->value == value)
		{
			cout << "Адрес элемента: " << current << endl;
			return;
		}
		value < current->value ? current = current->left : current = current->right;
	}

	cout << "Элемент не найден" << endl;
}

int BinaryTree::get_height()
{
	return get_nodes_max_height(root);
}

int BinaryTree::get_nodes_max_height(Node* peak)
{
	if (peak != nullptr)
	{
		int temp_left = get_nodes_max_height(peak->left);
		int	temp_right = get_nodes_max_height(peak->right);

		return 1 + max(temp_left, temp_right);
	}
	return 0;
}

void BinaryTree::print_tree(int& error_code)
{
	if (root == nullptr)
	{
		error_code = 1;
		return;
	}
	print_nodes(root);
}

void BinaryTree::print_nodes(Node* peak)
{
	if (peak != nullptr)
	{
		if (peak->left != nullptr || peak->right != nullptr)
		{
			if (peak->left != nullptr)
			{
				cout << peak->value;
				cout << " -> left: " << peak->left->value << "; ";
			}
			if (peak->right != nullptr)
			{
				cout << peak->value;
				cout << " -> right: " << peak->right->value << "; ";
			}
		}
		else
		{
			cout << peak->value << ";";
		}
		cout << endl;
		print_nodes(peak->left);
		print_nodes(peak->right);
	}
}

void BinaryTree::get_even_node(Node* peak, int& sum)
{
	if (peak != nullptr)
	{
		get_even_node(peak->left, sum);
		get_even_node(peak->right, sum);
		if (peak->value % 2 == 0)
			sum++;
	}
}

void BinaryTree::delete_tree(Node* peak)
{
	if (peak == nullptr)
		return;
	delete_tree(peak->left);
	delete_tree(peak->right);
	delete peak;
}

int BinaryTree::get_nodes_count()
{
	return get_nodes_count(root);
}

int BinaryTree::get_even_nodes_sum()
{
	int sum = 0;
	get_even_node(root, sum);
	return sum;
}

int BinaryTree::get_nodes_count(Node* peak)
{
	if (peak != nullptr)
	{
		int leftsum = get_nodes_count(peak->left);
		int rightsum = get_nodes_count(peak->right);

		return 1 + leftsum + rightsum;
	}
	return 0;
}