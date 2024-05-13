#include <iostream>
using namespace std;
template <typename T>
class MyNormalList {
private:
	class Node {
	public:
		T elem;
		Node* next;
		Node* prev;
		Node(const T& value) : elem(value), next(nullptr) , prev(nullptr) {};
	};
	Node* head;
	Node* tail;
	int size;
public:
	MyNormalList() : head(nullptr), tail(nullptr), size(-1) {};
	~MyNormalList() {
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
		tail = nullptr;
		size = -1;
	}
	bool operator == (const MyNormalList& otherList) {
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
	bool operator !=(const MyNormalList& otherList) {
		return !(this == otherList);
	}
	void pushFront(const T& value) {
		Node* newNode = new Node(value);
		if (this.empty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void popFront() {
		if (empty()) throw out_of_range("Error");
		if (head->next == nullptr) {
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* buf = head->next;
			delete head;
			head = buf;
			head->prev = nullptr;
		}
		size--;
	}
	bool empty()const {
		return head == nullptr;
	}
	void pushBack(const T& value) {
		Node* newNode = new Node(value);
		if (this->empty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
	}
	void popBack() {
		if (empty()) throw out_of_range("Error");
		if (head->next == nullptr) {
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* buf = tail->prev;
			delete tail;
			tail = buf;
			tail->next = nullptr;
		}
		size--;
	}
	bool checkIndex(int index) {
		return (this->size / 2 > index);
	}
	void insertAfter(const T& value, int index) {
		if (empty() || index < 0 || index > this->size)throw out_of_range("Error");
		Node* cur;
		if (checkIndex(index)) {
			cur = head;
			for (int i = 0; i < index; i++) {
				cur = cur->next;
			}
		}
		else {
			cur = tail;
			for (int i = size; i > index; i--) {
				cur = cur->prev;
			}
		}
		Node* buf = cur->next;
		cur->next = new Node(value);
		cur->next->next = buf;
		buf->prev->prev = cur;
		size++;
	}
	void erase(int index) {
		if (empty() || index < 0 || index > this->size)throw out_of_range("Error");
		Node* cur;
		if (checkIndex(index)) {
			cur = head;
			for (int i = 0; i < index; i++) {
				cur = cur->next;
			}
		}
		else {
			cur = tail;
			for (int i = size; i > index; i--) {
				cur = cur->prev;
			}
		}
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		delete cur;
		size--;
	}
	void erase(int index1, int index2) {
		if (empty() || index1 < 0 || index1 > this->size || index2 < 0 || index2 > this->size)throw out_of_range("Error");
		if (index1 > index2) swap(index1, index2);
		Node* buf1;
		Node* buf2;
		if (checkIndex(index1)) {
			buf1 = head;
			for (int i = 0; i < index1; i++) {
				buf1 = buf1->next;
			}
		}
		else {
			buf1 = tail;
			for (int i = size; i > index1; i--) {
				buf1 = buf1->prev;
			}
		}
		if (checkIndex(index2)) {
			buf2 = head;
			for (int i = 0; i < index2; i++) {
				buf2 = buf2->next;
			}
		}
		else {
			buf2 = tail;
			for (int i = size; i > index2; i--) {
				buf2 = buf2->prev;
			}
		}
		buf1 = buf1->prev;
		buf2 = buf2->next;
		Node* cur = buf1->next;
		Node* buf3;
		for (int i = index1; i < index2; i++) {
			buf3 = cur->next;
			delete cur;
			cur = buf3;
			size--;
		}
		buf1->next = buf2;
		buf2->prev = buf1;
	}

	void emplace(const T& value, int index) {
		if (empty() || index < 0 || index > this->size)throw out_of_range("Error");
		Node* cur;
		if (checkIndex(index)) {
			cur = head;
			for (int i = 0; i < index; i++) {
				cur = cur->next;
			}
		}
		else {
			cur = tail;
			for (int i = size; i > index; i--) {
				cur = cur->next;
			}
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
	T& back() {
		return tail->elem;
	}
	MyNormalList& operator =(const MyNormalList& otherList) {
		this->clear();
		if (otherList.empty()) return *this;
		Node* cur = otherList.head;
		while (cur != nullptr) {
			this->pushBack(cur->elem);
			cur = cur->next;
		}
		this->size = otherList->size;
		return *this;
	}
	MyNormalList(const MyNormalList& otherList) {
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
	MyNormalList<int> MyList;
	for (int i = 1; i < 41; i++) {
		MyList.pushBack(i);
	}
	for (auto el : MyList) {
		cout << el << " ";
	}
	cout << endl;
	MyList.erase(2, 5);
	for (auto el : MyList) {
		cout << el << " ";
	}
	cout << endl;
}