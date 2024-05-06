#include <iostream>
using namespace std;
template <typename T>
class MyForwardList {
private:
	class Node {
	public:
		T elem;
		Node* next;

		Node(const T& value) : elem(value), next(nullptr){};
	};
	Node* head;

public:
	MyForwardList() : head(nullptr){};
	~MyForwardList() {

	}
	void pushFront(const T& value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}
	void popFront() {
		if (empty()) throw out_of_range("Error");
		Node* buf = head->next;
		delete head;
		head = buf;
	}
	bool empty()const {
		return head == nullptr;
	}
	void pushBack(const T& value) {
		Node* cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = new Node(value);
	}
	void popBack() {
		if (empty()) throw out_of_range("Error");
		Node* cur = head;
		while ((cur->next)->next != nullptr) {
			cur = cur->next;
		}
		delete cur->next;
		cur->next = nullptr;
	}
	void insertAfter(const T& value, int index) {
		for (int i = 0; i <= index + 1; i++){
			if (cur->next == nulptr) throw out_of_range("Error");
		}
	}
	void emplaceAfter(const T& value, int index) {
		for (int i = 0; i <= index; i++) {
			if (cur->next == nulptr) throw out_of_range("Error");
		}
	}
	void show() {
		Node* cur = head;
		while (cur->next != nullptr) {
			cout << cur->elem << " ";
			cur = cur->next;
		}
		cout << cur->elem << endl;
	}
};
int main()
{
	MyForwardList<int> MyList;
	MyList.pushBack(10);
	MyList.pushBack(20);
	MyList.show();
}