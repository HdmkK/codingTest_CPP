#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int value;
	Node* left, * right;

public:
	Node(int value)
		:value(value), left(nullptr), right(nullptr) 
	{}
};

class BST
{
private:
	Node* root;

	Node* insertNode(Node* node, int key)
	{
		if (!node) {
			return new Node(key);
		}

		if (key < node->value) {
			node->left = insertNode(node->left, key);
		}
		else {
			node->right = insertNode(node->right, key);
		}
		return node;
	}

	bool searchNode(Node* node, int key)
	{
		if (!node)
			return false;

		if (node->value == key) {
			return true;
		}

		return (node->value > key) ?
			searchNode(node->left, key) :
			searchNode(node->right, key);
	}

public:
	BST() : root(nullptr) {}

	void insert(int key)
	{
		root = insertNode(root, key);
	}

	bool search(int key)
	{
		return searchNode(root, key);
	}
};


vector<bool> solution(const vector<int>& lst, const vector<int>& search_lst) {
	vector<bool> answer;

	BST bst;

	for (int key : lst) {
		bst.insert(key);
	}

	for (int key : search_lst) {
		answer.push_back(bst.search(key));
	}

	return answer;
}

int main() {
	/*vector<int> lst{ 5,3,8,4,2,1,7,10 };
	vector<int> search_lst{ 1,2,5,6 };*/

	vector<int> lst{ 1,3,5,7,9 };
	vector<int> search_lst{ 2,4,6,8,10 };
	vector<bool> result = solution(lst, search_lst);
	for (auto v : result) {
		cout << v << " ";
	}
	return 0;
}