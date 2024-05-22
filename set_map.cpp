#include <iostream>
using namespace std;

template <typename T, typename T2>
class MySet {
private:
	class Node {
	public:
		T key;
		T2 value;
		Node* left = nullptr;
		Node* right = nullptr;
		Node(T& key, T2 value) : key(key), value(value) {};
	};
	Node* root;
public:
	MySet() : root(nullptr) {};
	//~Set() {

	//}
	void insert(T key, T2 value) {
		root = insertRecursive(root, key, value);
	}
	void show() {
		if (this->root != nullptr) {
			showRecursive(root);
		}
		cout << endl;
	}
	void remove(T key) {
		removeRecursive(key, this);
	}
private:
	void showRecursive(Node* node) {
		if (node != nullptr) {
			showRecursive(node->left);
			cout << node->key << " : " << node->value << ", ";
			showRecursive(node->right);
		}
	}
	Node* insertRecursive(Node* node, T& key, T2 value) {
		if (node == nullptr) {
			return new Node(key, value);
		}
		if (key < node->key) {
			node->left = insertRecursive(node->left, key, value);
		}
		else if (key > node->key) {
			node->right = insertRecursive(node->right, key, value);
		}
		return node;
	}
	void removeRecursive(T key, Node node) {
		if (key > node.key) {
			if (key == node.right.key) {
				
			}
			else {
				removeRecursive(key, node.right);
			}
			
		}
		else if (key < node.key) {
			removeRecursive(key, node.left);
		}
		if (node.left == nullptr && node.right == nullptr) {

		}
		else if ((node.left == nullptr && node.right != nullptr) || (node.left != nullptr && node.right == nullptr)) {

		}
		else {

		}
	}
	void 
};
int main()
{
	MySet<int, char> set;
	set.insert(1, 'q');
	set.insert(2, 'w');
	set.insert(3, 'e');
	set.insert(4, 'r');
	set.show();

}
