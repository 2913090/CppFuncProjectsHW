#include <iostream>
#define random(min, max) (min + rand()%(max-min+1))
using namespace std;
void showarray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void fillarray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		array[i] = random(0, 100);
	}
}
void quicksortrecursive(int* array, int left, int right) {
	if (right <= left) return;
	int wall = left - 1;
	for (int i = left; i <= right; i++) {
		if (array[i] <= array[right]) {
			++wall;
			if (i > wall) {
				swap(array[i], array[wall]);
			}
		}
	}
	quicksortrecursive(array, left, wall - 1);
	quicksortrecursive(array, wall + 1, right);

}

void quicksort(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	quicksortrecursive(array, 0, size - 1);
}

int main()
{
	srand(time(NULL));
	int* array = new int[10];
	fillarray(array);
	showarray(array);
	quicksort(array);
	showarray(array);
}