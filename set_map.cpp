#include <iostream>
using namespace std;

template <typename T, typename T2>
class MyMap {
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
	MyMap() : root(nullptr) {};
	//~MyMap() {

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
	T2& operator [](T key) {
		if (findNodeRecursive(this->root, key) == nullptr) throw out_of_range("error");
		return (findNodeRecursive(this->root, key)->value);
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
	void removeRecursive(T key, Node delNode) {
		if (key > delNode->key) {
			Node* preNode = new Node[findPreNodeRecursive(delNode, delNode->right, key)];
		}
		else if (key < delNode->key) {
			Node* preNode = new Node[findPreNodeRecursive(delNode, delNode->left, key)];
		}
		else {

			remove;
		}
		if (delNode->left == nullptr && delNode->right == nullptr) {
			if (preNode->right == delNode) {
				delete delNode;
				preNode->right = nullptr;
			}
			else if (preNode->left == delNode) {
				delete delNode;
				preNode->left = nullptr;
			}
		}
		else if ((delNode->left == nullptr && delNode->right != nullptr) || (delNode->left != nullptr && delNode->right == nullptr)) {

		}
		else {
			if (delNode)
		}
	}
	 
	Node* findPreNodeRecursive(Node* node1, Node* node2, T& key) {
		if (node2 == nullptr) return nullptr;
		else if (node2->key < key) {
			node1 = node2;
			node2 = node2->right;
			return findPreNodeRecursive(node1, node2, key);
		}
		else if (node2->key > key) {
			node1 = node2;
			node2 = node2->left;
			return findPreNodeRecursive(node1, node2, key);
		}
		else if (node2->key == key) return node1;
	}

	Node* findNodeRecursive(Node* node, T& key) {
		if (key > node->key) return findNodeRecursive(node->right, key);
		else if (key < node->key) return findNodeRecursive(node->left, key);
		else if (key == node->key) return node;
		else return nullptr;
	}

	Node* searchMinNode(Node* node) {

	}
};
int main()
{
	MyMap<int, char> set;
	set.insert(1, 'q');
	set.insert(2, 'w');
	set.insert(3, 'e');
	set.insert(4, 'r');
	set.show();
	cout << set[4];

}
