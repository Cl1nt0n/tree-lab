#include <iostream>
using namespace std;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void print_tree(int &error_code);
	void insert_element(int value, int& error_code);
	void remove_element(int value, int& error_code);
	void find_element(int value);
	int get_even_nodes_sum();
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
	void get_even_node(Node* peak, int &sum);
	void delete_tree(Node* peak);
	Node* root;
};