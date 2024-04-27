#include <iostream>
using namespace std;

template<typename T>
class MyStack {
private:
	T* elements;
	int capacity;
	int topIndex;

public:
	MyStack() : capacity(10), topIndex(-1) {
		this->elements = new T[capacity];
	}

	~MyStack() {
		delete[] this->elements;
	}

	void push(const T& elem) {
		if (topIndex >= capacity) {
			capacity *= 2;
			T* buf = new T[capacity];
			for (int i = 0; i < topIndex; i++){
				buf[i] = this->elements[i];
			}
			delete[] this->elements;
			this->elements = buf;
		}
		elements[++topIndex] = elem;
	}

	void show() {
		for (int i = 0; i <= topIndex; i++){
			cout << this->elements[i] << " ";
		}
		cout << endl;
	}

	bool empty() {
		return (topIndex == -1) ? true : false;
	}

	void pop() {
		(empty()) ? throw out_of_range("Stack is empty") : topIndex--;
	}

	T& top() {
		return (empty()) ? throw out_of_range("Stack is empty") : this->elements[topIndex];
	}

	int size() {
		return this->topIndex + 1;
	}

	void set(const T& elem) {
		(empty()) ? throw out_of_range("Stack is empty") : this->elements[topIndex] = elem;
	}

	MyStack& operator =(const MyStack other) {
		this->capacity = other.capacity;
		this->topIndex = other.topIndex;
		T* buf = new T[other.capacity];
		for (int i = 0; i <= other.topIndex; i++){
			buf[i] = other.elements[i];
		}
		delete[] this->elements;
		this->elements = buf;
		return *this;
	}

	MyStack(const MyStack& other) {
		delete[] this->elements;
		this->topIndex = other.topIndex;
		this->capacity = other.capacity;
		this->elements = new T[capacity];
		for (int i = 0; i <= this->topIndex; i++) {
			this->elements[i] = this->elements[i];
		}
	}

	bool operator ==(const MyStack other) {
		if (this->topIndex != other.topIndex) return false;
		for (int i = 0; i <= other.topIndex; i++){
			if (this->elements[i] != other.elements[i]) return false;
		}
		return true;
	}

	bool operator !=(const MyStack other) {
		if (this->topIndex != other.topIndex) return true;
		for (int i = 0; i <= other.topIndex; i++) {
			if (this->elements[i] != other.elements[i]) return true;
		}
		return false;
	}
};

int main()
{
	MyStack<int> stack1;
	stack1.push(76);
	stack1.push(98);
	stack1.push(82);
	MyStack<int> stack2;
	stack2 = stack1;
	stack1.show();
	stack2.show();
}