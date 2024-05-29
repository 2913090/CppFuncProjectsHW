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
		removeContinue(key, this->root);
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
	/*void removeContinue(T key, Node delNode) {
		Node* thatNode = findNodeRecursive(delNode, key);
		if (thatNode == nullptr) throw out_of_range("error");
		Node* preNode;
		if (key > delNode->key) {
			preNode = new Node[findPreNodeRecursive(delNode, delNode->right, key)];
		}
		else if (key < delNode->key) {
			preNode = new Node[findPreNodeRecursive(delNode, delNode->left, key)];
		}
		else {
			if (thatNode->right != nullptr) {
				Node* minRightNode = searchMinNode();
				this->root =
					if ()
				return;
			}
			else if (thatNode->right == nullptr && thatNode->left == nullptr) {
				delete thatNode;
				this->root = nullptr;
				return;
			}
			else if ()
		}

		if (thatNode->left == nullptr && thatNode->right == nullptr) {
			if (preNode->right == nullptr) {
				delete thatNode;
				preNode->right = nullptr;
			}
			else if (preNode->left == thatNode) {
				delete thatNode;
				preNode->left = nullptr;
			}
		}
		else if ((thatNode->left == nullptr && thatNode->right != nullptr) || (thatNode->left != nullptr && thatNode->right == nullptr)) {

		}
		else {
			if (thatNode) {

			}
		}
	}*/
	

	void removeContinue(T key, Node* thatNode) {
		if (thatNode->key == key) {
			if (thatNode->right == nullptr && thatNode->left == nullptr) {
				this->root = nullptr;
				delete thatNode;
				return;
			}
			else if (thatNode->right == nullptr && thatNode->left != nullptr) {
				this->root = thatNode->left;
				delete thatNode;
				return;
			}
			else if (thatNode->right != nullptr && thatNode->left == nullptr) {
				this->root = thatNode->right;
				delete thatNode;
				return;
			}
			else if (thatNode->right != nullptr && thatNode->left != nullptr) {
				Node* minRightNode = searchMinNode(thatNode->right);
				Node* preMinRightNode = findPreNodeRecursive(thatNode, thatNode->right, minRightNode->key);
				preMinRightNode->left = nullptr;
				Node* rightChild = this->root->right;
				Node* leftChild = this->root->left;
				thatNode = minRightNode;
				minRightNode->right = rightChild;
				minRightNode->left = leftChild;
				return;
			}
		}
		Node* delNode = findNodeRecursive(thatNode, key);
		if (delNode->right == nullptr && delNode->left == nullptr) {

		}
		else if (delNode->right != nullptr && delNode->left == nullptr) {

		}
		else if (delNode->right == nullptr && delNode->left != nullptr) {

		}
		else if (delNode->right != nullptr && delNode->left != nullptr) {
			Node* minRightNode = searchMinNode(delNode->right);
			Node* preMinRightNode = findPreNodeRecursive(delNode, delNode->right, minRightNode->key);
			preMinRightNode->left = nullptr;
			Node* rightChild = delNode->right;
			Node* leftChild = delNode->left;
			Node* preDelNode = findPreNodeRecursive(delNode, (thatNode->key > delNode->key) ? thatNode->left : thatNode->right, delNode->key);
			thatNode = minRightNode;
			minRightNode->right = rightChild;
			minRightNode->left = leftChild;
			return;
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
		if (node->left == nullptr) {
			return node;
		}
		else {
			searchMinNode(node->left);
		}
	}
};
int main()
{
	MyMap<int, char> set;
	set.insert(3, 'q');
	set.insert(7, 'w');
	set.insert(9, 'e');
	set.insert(6, 'r');
	set.insert(8, 't');
	set.insert(2, 'y');
	set.show();
	//cout << set[4];
	set.remove(7);
	set.show();
}
