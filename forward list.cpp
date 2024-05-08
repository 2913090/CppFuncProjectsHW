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
		if (empty()) return;
		Node* buf;
		Node* cur = head;
		while (cur->next != nullptr) {
			buf = cur->next;
			delete cur;
			cur = buf;
		}
		delete cur;
	}
	void clear() {
		if (empty()) return;
		Node* buf;
		Node* cur = head;
		while (cur->next != nullptr) {
			buf = cur->next;
			delete cur;
			cur = buf;
		}
		delete cur;
		head = nullptr;
	}
	bool operator == (const MyForwardList& otherList) {
		Node* cur1 = this->head;
		Node* cur2 = otherList.head;
		while (true) {
			if ((cur1 == nullptr && cur2 != nullptr) || (cur1 != nullptr && cur2 == nullptr)) return false;
			else if (cur1 == nullptr && cur2 == nullptr) break;
			else if (cur1->elem != cur2->elem) return false;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return true;
	}
	bool operator !=(const MyForwardList& otherList) {
		return !(this == otherList);
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
		if (empty()) {
			head = new Node(value);
			return;
		}
		Node* cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = new Node(value);
	}
	void popBack() {
		if (empty()) throw out_of_range("Error");
		Node* cur = head;
		while (cur->next->next != nullptr) {
			cur = cur->next;
		}
		delete cur->next;
		cur->next = nullptr;
	}
	void insertAfter(const T& value, int index) {
		if (empty() || index < 0)throw out_of_range("Error");
		Node* cur = head;
		for (int i = 0; i < index; i++){
			if (cur->next == nullptr) throw out_of_range("Error");
			cur = cur->next;
		}
		Node* buf = cur->next;
		cur->next = new Node(value);
		cur->next->next = buf;
	}
	void emplace(const T& value, int index) {
		if (empty() || index < 0)throw out_of_range("Error");
		Node* cur = head;
		for (int i = 0; i < index; i++) {
			if (cur->next == nullptr) throw out_of_range("Error");
			cur = cur->next;
		}
		cur->elem = value;
	}
	void show() {
		if (empty()) return;
		Node* cur = head;
		while (cur->next != nullptr) {
			cout << cur->elem << " ";
			cur = cur->next;
		}
		cout << cur->elem << endl;
	}
	T& front() {
		return head->elem;
	}
	MyForwardList& operator =(const MyForwardList& otherList) {
		this->clear();
		if (otherList.empty()) return *this;
		Node* cur = otherList.head;
		while (cur != nullptr) {
			this->pushBack(cur->elem);
			cur = cur->next;
		}
		return *this;
	}
	MyForwardList(const MyForwardList& otherList) {
		if (otherList.empty()) return;
		Node* otherCur = otherList.head;
		this->pushBack(otherCur->elem);
		while (otherCur->next != nullptr) {
			otherCur = otherCur->next;
			this->pushBack(otherCur->elem);
		}
	}
	class Iterator {
	private:
		Node* ptr;
	public:
		Iterator(Node* ptr) {
			this->ptr = ptr;
		}
		~Iterator() {
			delete ptr;
		}
		T& operator *() const {
			return ptr->elem;
		}
		Iterator& operator++() {
			ptr = ptr->next;
			return *this;
		}
		Iterator operator++(int) {
			Iterator temp = *this;
			ptr = ptr->next;
			return temp;
		}
		bool operator==(const Iterator& other) const {
			return this->ptr == other.ptr;
		}
		bool operator!=(const Iterator& other) const {
			return this->ptr != other.ptr;
		}
		Iterator& operator +(int num) {
			Iterator iter = Iterator(this->ptr + num);
			return iter;
		}
	};
	Iterator begin() {
		return Iterator(this->head);
	}

	Iterator end() {
		return Iterator(nullptr);
	}
};
int main()
{
	MyForwardList<int> MyList;
	MyList.pushBack(10);
	MyList.pushBack(20);
	MyList.pushBack(30);
	MyList.pushBack(40);
	//MyList.show();
	MyForwardList<int> MyList2;
	MyList2.pushBack(10);
	MyList2.pushBack(20);
	//MyList2.show();
	//cout << (MyList == MyList2) << endl;
	MyList2 = MyList;
	//MyList2.show();
	//cout << (MyList == MyList2) << endl;
	MyForwardList<int> MyList3 = MyList;
	//MyList3.show();
	for (auto el : MyList) {
		cout << el << " ";
	}
	cout << endl;
}
