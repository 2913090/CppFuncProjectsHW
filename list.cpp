#include <iostream>

using namespace std;


template <typename T>
class MyList {
private:
	int capacity = 10;
	int size = 0;
	T* array;
public:
	MyList() {
		this->array = new T[capacity];
	}

	T& front() {
		return array[0];
	}

	T& back() {
		return array[size - 1];
	}

	bool empty() {
		return (size > 0) ? false : true;
	}

	int getSize() {
		return this->size;
	}

	void pushBack(T elem) {
		increaseList();
		array[size++] = elem;
	}

	void insert(T elem, int index) {
		increaseList();
		if (index >= size || index < 0) return;
		for (int i = size; i >= index; i--) {
			swap(array[i], array[i + 1]);
		}
		array[index] = elem;
		size++;
	}

	void pushFront(T elem) {
		insert(elem, 0);
	}

	void show() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void clear() {
		this->capacity = 10;
		this->size = 0;
		delete[] this->array;
		this->array = new T[this->capacity];
	}

	void pop(int index) {
		if (index >= size || index < 0) return;
		for (int i = index; i < size; i++) {
			swap(array[i], array[i + 1]);
		}
		size--;
	}

	void popBack() {
		size--;
	}

	void popFront() {
		pop(0);
	}

	~MyList() {
		delete[] this->array;
	}

	void insertRange(int index, T* arr, int size) {
		increaseList(size);
		if (index >= size || index < 0) return;
		for (int i = this->size; i >= index; i--) {
			swap(array[i], array[i + size]);
		}
		for (int i = 0; i < size; i++) {
			this->array[index + i] = arr[i];
		}
		this->size += size;
	}
private:
	void increaseList(int count = 1) {
		if ((this->size + count) >= (this->capacity * 0.75)) {
			this->capacity *= 1.5;
			if (this->capacity < (size + count)) this->capacity += count;
			T* buf = new T[this->capacity];
			for (int i = 0; i < size; i++)
			{
				buf[i] = array[i];
			}
			delete[] array;
			array = buf;
		}
	}
};


int main()
{

	MyList<int> list;
	int* massiv = new int[20];
	for (int i = 0; i < 20; i++){
		massiv[i] = i;
		cout << massiv[i] << " ";
	}
	cout << endl;
	list.pushBack(15);
	list.pushBack(20);
	list.pushFront(5);
	list.insert(10, 1);
	list.show();
	list.pop(3);
	list.show();
	list.insertRange(2, massiv, 20);
	list.show();




}