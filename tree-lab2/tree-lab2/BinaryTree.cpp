#include "BinaryTree.h"

void BinaryTree::print_tree(Node* root)
{
	if (root != nullptr) 
	{ //Пока не встретится пустой узел
		print_tree(root->left); //Рекурсивная функция для левого поддерева
		cout << tree->field; //Отображаем корень дерева
		treeprint(tree->right); //Рекурсивная функция для правого поддерева
	}
}

BinaryTree::Node* BinaryTree::get_root()
{
	return _root;
}
