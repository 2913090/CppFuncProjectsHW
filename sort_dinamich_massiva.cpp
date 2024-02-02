#include <iostream>
#define random(min, max) (min + rand()%(max-min+1))
using namespace std;
void fillarray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		array[i] = random(0, 100);
	}
}
void showarray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void sortarray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	int count = 0;
	for (int q = size - 1; q > 0; q--) {
		bool flag = true;
		for (int w = 0; w < q; w++) {
			if (array[w] > array[w + 1]) {
				swap(array[w], array[w + 1]);
				flag = false;
				count++;
			}
		}
		if (flag)
			break;
	}
}
int main()
{
	srand(time(NULL));
	int* array = new int[10];
	fillarray(array);
	showarray(array);
	sortarray(array);
	showarray(array);
}