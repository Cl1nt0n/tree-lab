class BinaryTree
{
public:
	class Node 
	{
		int value;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	BinaryTree();
	~BinaryTree();
	//Удаление
	void remove(int value, int& error_code);
	//Добавление
	void insert(int value, int& error_code);
	//печать дерева
	void print_tree(Node* root);
	//поиск
	Node* find(int value);
	//получить корневой элемент
	Node* get_root();
private:
	//корневой элемент
	Node* _root;
	//удаление элемента
	void delete_tree(Node* vertex);
};
