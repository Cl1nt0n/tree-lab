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
	//��������
	void remove(int value, int& error_code);
	//����������
	void insert(int value, int& error_code);
	//������ ������
	void print_tree(Node* root);
	//�����
	Node* find(int value);
	//�������� �������� �������
	Node* get_root();
private:
	//�������� �������
	Node* _root;
	//�������� ��������
	void delete_tree(Node* vertex);
};
