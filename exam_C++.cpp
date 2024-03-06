#include <iostream>
#define random(min, max) (min+rand()%(max-min+1))
using namespace std;

template <typename T>
void showArray(T** array) {
	int size2;
	int size1 = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size1; i++) {
		size2 = _msize(array[i]) / sizeof(array[i][0]);
		for (int j = 0; j < size2; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}




template <typename T>
void copyArray(T** array1, T** array2) {
	int size1 = _msize(array1) / sizeof(array1[0]);
	int size2 = _msize(array1[0]) / sizeof(array1[0][0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			array2[i][j] = array1[i][j];
		}
	}
}


template <typename T>
void delElem(T* &array, int index) {
	int size = _msize(array) / sizeof(array[0]);
	if (index >= size) {
		cout << "ERROR\n";
		return;
	}
	T* buf = new int[size - 1];
	for (int i = 0; i < index; i++) {
		buf[i] = array[i];
	}
	for (int i = index + 1; i < size; i++) {
		buf[i - 1] = array[i];
	}
	delete[] array;
	array = buf;
}

template <typename T>
void addArray(T** &array1, T* array2, int index) {
	int size1 = _msize(array1) / sizeof(array1[0]);
	int size2 = _msize(array1[0]) / sizeof(array1[0][0]);
	int size3 = _msize(array2) / sizeof(array2[0]);
	T** buf1 = new int*[size1 + 1];
	for (int i = 0; i < index; i++) {
		buf1[i] = array1[i];
	}
	T* buf2 = new int [size3];
	for (int i = 0; i < size3; i++) {
		buf2[i] = array2[i];
	}
	buf1[index] = array2;
	for (int i = index; i < size2; i++) {
		buf1[i + 1] = array1[i];
	}
	delete[] array1;
	array1 = buf1;
}

template <typename T>
void delVert(T** &array, int index) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);

}

template <typename T>
void delMinElemStroke(T**& array) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	T min = array[0][0];
	int index;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (min > array[i][j]) {
				min = array[i][j];
				index = i;
			}
		}
	}

}
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	//1
	
	//float a1, b1, c1, d1;
	//cout << "Введите 1-е число: ";
	//cin >> a1;
	//cout << "Введите 2-е число: ";
	//cin >> b1;
	//cout << "Введите 3-е число: ";
	//cin >> c1;
	//cout << "Введите 4-е число: ";
	//cin >> d1;
	//cout << "Среднее арифметическое чисел: " << a1 << ", " << b1 << ", " << c1 << ", " << d1 << " = " << (a1 + b1 + c1 + d1) / 4 << endl;



	//2

	//int start = 1;
	//int end = 40;
	//if (start % 2 != 0)start++;
	//for (int i = start; i <= end; i += 2) {
	//	cout << i << " ";
	//}
	//cout << endl;



	//3

	//int storona;
	//cout << "Введите сторону квадрата\n";
	//cin >> storona;
	//for (int i = 0; i <= storona; i++) {
	//	for (int j = 0; j < i; j++) {
	//		cout << "* ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;



	//4

	//int number;
	//cout << "Введите число\n";
	//cin >> number;
	//int count = 0;
	//while (number != 0) {
	//	number /= 10;
	//	count++;
	//}
	//cout << "Введенное число состоит из " << count << " разрядов\n";
	//cout << endl;



	//5

	//int const SIZE = 10;
	//int array5[SIZE];
	//int min, max;
	//cout << "Введите наименьшее значение\n";
	//cin >> min;
	//cout << "Введите наибольшее значение\n";
	//cin >> max;
	//for (int i = 0; i < SIZE; i++) {
	//	array5[i] = random(min, max);
	//}
	//for (int i = 0; i < SIZE; i++) {
	//	cout << array5[i] << " ";
	//}
	//cout << endl;
	//cout << endl;



	//6

	//int size61 = 4, size62 = 4;
	//int** array6 = new int* [size61];
	//for (int i = 0; i < size61; i++) {
	//	array6[i] = new int[size62];
	//}
	//for (int i = 0; i < size61; i++) {
	//	for (int j = 0; j < size62; j++) {
	//		array6[i][j] = random(1, 100);
	//		cout << array6[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//int* sum6 = new int[size61]{};
	//for (int i = 0; i < size61; i++) {
	//	for (int j = 0; j < size62; j++) {
	//		sum6[i] += array6[i][j];
	//	}
	//}
	//int index = 0;
	//for (int max6 = sum6[0], i = 1; i < size61; i++) {
	//	if (max6 < sum6[i]) {
	//		max6 = sum6[i];
	//		index = i;
	//	}
	//}
	//cout << "В строке номер " << index + 1 << " сумма элементов наибольшая\n";
	//cout << endl;



	//7

	//int size71 = 4, size72 = 4;
	//int** array71 = new int* [size71];
	//for (int i = 0; i < size71; i++) {
	//	array71[i] = new int[size72];
	//}
	//for (int i = 0; i < size71; i++) {
	//	for (int j = 0; j < size72; j++) {
	//		array71[i][j] = random(1, 100);
	//		cout << array71[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//int** array72 = new int* [size71];
	//for (int i = 0; i < size71; i++) {
	//	array72[i] = new int[size72];
	//}
	//copyArray(array71, array72);
	//for (int i = 0; i < size71; i++) {
	//	for (int j = 0; j < size72; j++) {
	//		cout << array72[i][j] << " ";
	//	}
	//	cout << endl;
	//}



	//8

	//int* array8 = new int [5];
	//for (int i = 0; i < 5; i++) {
	//	array8[i] = random(1, 100);
	//	cout << array8[i] << " ";
	//}
	//cout << endl;
	//delElem(array8, 3);
	//for (int i = 0; i < 4; i++) {
	//	cout << array8[i] << " ";
	//}
	//cout << endl;



	//9

	//int size91 = 4, size92 = 4;
	//int** array91 = new int* [size91];
	//for (int i = 0; i < size91; i++) {
	//	array91[i] = new int[size92];
	//}
	//for (int i = 0; i < size91; i++) {
	//	for (int j = 0; j < size92; j++) {
	//		array91[i][j] = random(1, 100);
	//		cout << array91[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//int* array92 = new int [4];
	//for (int i = 0; i < 4; i++) {
	//	array92[i] = random(1, 100);
	//	cout << array92[i] << " ";
	//}
	//cout << endl;
	//cout << endl;
	//addArray(array91, array92, 1);
	//showArray(array91);

	//10

	int size101 = 4, size102 = 4;
	int** array10 = new int* [size101];
	for (int i = 0; i < size101; i++) {
		array10[i] = new int[size102];
	}
	for (int i = 0; i < size101; i++) {
		for (int j = 0; j < size102; j++) {
			array10[i][j] = random(1, 100);
			cout << array10[i][j] << " ";
		}
		cout << endl;
	}
	delVert(array10, 3);
}