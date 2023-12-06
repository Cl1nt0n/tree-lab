#include "BinaryTree.h"

void BinaryTree::print_tree(Node* root)
{
	if (root != nullptr) 
	{ //���� �� ���������� ������ ����
		print_tree(root->left); //����������� ������� ��� ������ ���������
		cout << tree->field; //���������� ������ ������
		treeprint(tree->right); //����������� ������� ��� ������� ���������
	}
}

BinaryTree::Node* BinaryTree::get_root()
{
	return _root;
}
