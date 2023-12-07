#include <iostream>
using namespace std;
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void print_tree();
	void insert(int value, int& error_code);
	void remove_element(int value);
	int find_element(int value);
	int get_height();
	int get_nodes_count();
private:
	class Node 
	{
	public:
		int value;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(int value)
		{
			this->value = value;
		}
	};

	int get_nodes_count(Node* peak);
	int get_nodes_max_height(Node* peak);
	void print_nodes(Node* peak);
	Node* root;
};