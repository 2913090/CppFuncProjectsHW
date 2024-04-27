#include <iostream>
 
using namespace std;
 
 
template <typename T>
class MyVector {
private:
	int capacity = 10;
	int size = 0;
	T* array;
 
public:
	MyVector() {
		this->array = new T[capacity];
	}
	
	bool operator ==(T& other) {
		if (this->size != other.size)return false;
		for (int i = 0; i < size; i++){
			if (this->array[i] != other.array[i]) return false;
		}
		return true;
	}

	void operator =(T& other) {
		delete[] this->array;
		T* newArray = new T[other->capacity];
		for (int i = 0; i < size; i++) {
			newArray[i] = other.array[i]
		}
	}

	void sort(bool reverse = false) {
		if (reverse == false) {
			for (int i = 0; i < size; i++) {
				for (int j = 1; j < size; j++) {
					if (this->array[j - 1] > this->array[j]) swap(this->array[j - 1], this->array[j]);
				}
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				for (int j = 1; j < size; j++) {
					if (this->array[j - 1] < this->array[j]) swap(this->array[j - 1], this->array[j]);
				}
			}
		}
	}

	~MyVector() {
		delete[] array;
	}

	T& operator [](int index) {
		if (index < 0 || index >= size) throw out_of_range("Index out of range");
		return array[index];
	}
 
	T& front() {
		return array[0];
	}
 
	T& back() {
		return array[size - 1];
	}
 
	T& at(int index) {
		if (index >= size || index < 0) throw out_of_range("Out of range");
		return array[index];
	}
 
	bool empty() {
		if (this->size > 0) return false;
		return true;
	}
 
	int getSize() {
		return this->size;
	}
 
	void push_back(T elem) {
		increaseVector();
		this->array[this->size++] = elem;
	}
 
	void push_front(T elem) {
		insert(0, elem);
	}
 
	void insert(int index, T elem) {
		if (index >= size || index < 0) return;
		increaseVector();
		for (int i = size; i >= index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = elem;
		size++;
	}
 
	void clear() {
		this->capacity = 10;
		this->size = 0;
		delete[] this->array;
		this->array = new T[capacity];
	}
 
 
	void show() {
		for (int i = 0; i < size; i++) cout << array[i] << " ";
		cout << endl;
	}
 
	int max_size() {
		return INT_MAX;
	}
 
	void set(int index, T elem) {
		if (index >= size || index < 0) return;
		this->array[index] = elem;
	}
 
	class Iterator {
	private:
		T* ptr;
 
	public:
 
		Iterator(T* ptr) {
			this->ptr = ptr;
		}
 
		T& operator *() const {
			return *ptr;
		}
 
		Iterator& operator++() { // префиксный
			++ptr;
			return *this;
		}
 
		Iterator& operator--() { // префиксный
			--ptr;
			return *this;
		}
 
		Iterator operator++(int) { // постфиксный
			Iterator temp = *this;
			++ptr;
			return temp;
		}
 
		Iterator operator--(int) { // постфиксный
			Iterator temp = *this;
			--ptr;
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

		Iterator& operator -(int num) {
			Iterator iter = Iterator(this->ptr - num);
			return iter;
		}
 
	};
 
	typename MyVector<T>::Iterator erase(typename MyVector<T>::Iterator position) {
		if (position == this->end()) {
			throw out_of_range("Invalid operator");
		}
		for (auto it = position; it != this->end() - 1; ++it) {
			*it = *(it + 1);
		}
		--size;
		return position;
	}
	Iterator begin() {
		return Iterator(array);
	}
 
	Iterator end() {
		return Iterator(array + size);
	}
 
 
 
private:
	void increaseVector(int count=1) {
		if ((this->size + count) >= (this->capacity * 0.75)) {
			this->capacity *= 1.5;
			if (capacity < (size + count)) this->capacity += count;
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
 
	MyVector<int> vector;
 
 
	vector.push_back(5);
	vector.push_back(15);
	vector.push_back(10);
	vector.show();
	vector.push_front(100);
	vector.show();
 
	MyVector<int>::Iterator it = vector.begin();
 
	vector.erase(it);
 
	vector.show();
	vector.sort();
	vector.show();
}