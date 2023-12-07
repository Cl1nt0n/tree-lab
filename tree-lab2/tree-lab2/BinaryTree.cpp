#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = nullptr;
}

void BinaryTree::insert_element(int value, int& error_code)
{
	if (root == nullptr)
	{
		root = new Node(value);
		root->value = value;
		return;
	}
	Node* current = root, * previous;

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

void BinaryTree::remove_element(int value, int &error_code)
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

	if (current != nullptr)
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			current->value < previous->value ? previous->left = nullptr : previous->right = nullptr;
		}
		else if(current->left == nullptr)
		{
			current->value < previous->value ? previous->left = nullptr : previous->right = current->right;
		}
		else if (current->right == nullptr)
		{
			current->value < previous->value ? previous->left = current->left : previous->right = nullptr;
		}
		else
		{

		}
	}
}

int BinaryTree::find_element(int value)
{
	Node* current = root;

	while (current != nullptr)
	{
		if (current->value == value)
			return (int)current;
		value < current->value ? current = current->left : current = current->right;
	}

	return -1;
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

void BinaryTree::print_tree(int &error_code)
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
		cout << peak->value << '\t';
		print_nodes(peak->left);
		print_nodes(peak->right);
	}
}

int BinaryTree::get_nodes_count()
{
	return get_nodes_count(root);
}

int BinaryTree::get_even_nodes_sum()
{

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