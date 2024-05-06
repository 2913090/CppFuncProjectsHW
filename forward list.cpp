﻿#include <iostream>
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
		Node* newNode = new Node(value);
		cur = newNode;
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