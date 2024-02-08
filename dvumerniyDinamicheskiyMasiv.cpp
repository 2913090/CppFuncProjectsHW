#include <iostream>
using namespace std;
void fillDoubleArray(int** array) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	for (int q = 1, i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			array[i][j] = q++;
		}
	}
}
void showDoubleArray(int** array) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
void addarray(int** &array, int* array2, int index) {
	int size1 = _msize(array) / sizeof(array[0]);
	if (index < 0 || index > size1) {
		cout << "error" << endl;
		return;
	}
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	int** massiv = new int* [size1+1];
	massiv[index] = new int[size2];
	for (int i = 0; i < index; i++) {
		massiv[i] = array[i];
	}
	for (int i = 0; i < size2; i++) {
		massiv[index][i] = array2[i];
	}
	for (int i = index; i < size1; i++) {
		massiv[i+1] = array[i];
	}
	delete[] array;
	array = massiv;
}
void delarray(int**& array, int index) {
	int size1 = _msize(array) / sizeof(array[0]);
	if (index < 0 || index > size1-1) {
		cout << "error" << endl;
		return;
	}
	int** massiv = new int* [size1 - 1];
	for (int i = 0; i < index; i++) {
		massiv[i] = array[i];
	}
	for (int i = index + 1; i < size1; i++) {
		massiv[i - 1] = array[i];
	}
	delete[] array;
	array = massiv;
}
void addelements(int**& array, int* array2) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	int size3 = _msize(array2) / sizeof(array2[0]);
	if (size1 != size3) {
		cout << "error" << endl;
		return;
	}
	int** massiv = new int* [size1];
	for (int i = 0; i < size1; i++) {
		massiv[i] = new int[size2 + 1];
	}

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			massiv[i][j] = array[i][j];
		}
	}
	for (int i = 0; i < size1; i++) {
		massiv[i][size2] = array2[i];
	}
	for (int i = 0; i < size1; i++) {
		delete[] array[i];
		array[i] = massiv[i];
	}
	array = massiv;
}
int main()
{
	int row = 5;
	int column = 5;
	int** array = new int* [row];
	for (int i = 0; i < row; i++) {
		array[i] = new int[column];
	}
	fillDoubleArray(array);
	showDoubleArray(array);
	int* array2 = new int[column] {26, 27, 28, 29, 30};
	addarray(array, array2, 2);
	cout << endl;
	showDoubleArray(array);

	delarray(array, 1);
	cout << endl;
	showDoubleArray(array);

	cout << endl;
	addelements(array, array2);
	showDoubleArray(array);

}
