#include <iostream>
using namespace std;
const int SIZE2 = 5;
int stepen(int a, int b) {
	if (b == 0)
		return 1;
	else if (b == 1){
		return a;
	}
	else {
		for (int i = 0; i < b; i++)
			a *= a;
		return a;
	}
}
void poisk(int massiv[], const int SIZE,int ishi) {
	bool flag = 1;
	for (int i = 0; i < SIZE; i++) {
		if (ishi == massiv[i]) {
			cout << "Искомое значение находится в " << i << " ячейке" << endl;
			flag = 0;
		}
	}
	if (flag) {
		cout << "Совпадений не найдено" << endl;
	}
}

int binar(int massiv[], const int SIZE, int naidi) {
	int nachalo = 0, konec = SIZE - 1;
	while (true) {
		if (massiv[nachalo + (konec - nachalo) / 2] > naidi) {
			konec = nachalo + (konec - nachalo) / 2;
		}
		else if (massiv[nachalo + (konec - nachalo) / 2] < naidi) {
			nachalo = nachalo + (konec - nachalo) / 2;
		}
		else if (massiv[nachalo + (konec - nachalo) / 2] == naidi) {
			return nachalo + (konec - nachalo) / 2;
		}
		if (nachalo == konec - 1) {
			cout << "error";
			return -1;
		}
	}
}




int dvavdesyat(int a) {
	int b=0, otvet = 0;
	do {
		otvet = otvet + stepen(2, b) * (a % 10);
		b++;
		a /=10;
	} while (a > 0);
	return otvet;
}



void matrica1(int massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE2; j++) {
			massiv[i][j] = rand() % 10;
		}
	}
}

void matrica1(double massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE2; j++) {
			massiv[i][j] = (rand() % 100) / 10.0;
		}
	}
}

void matrica1(char massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE2; j++) {
			massiv[i][j] = rand() % 256;
		}
	}
}









void matrica2(int massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE2; j++) {
			cout << massiv[i][j] << "\t";
		}
		cout << endl;
	}
}

void matrica2(double massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE2; j++) {
			cout << massiv[i][j] << "\t";
		}
		cout << endl;
	}
}

void matrica2(char massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE2; j++) {
			cout << massiv[i][j] << "\t";
		}
		cout << endl;
	}
}




int matrica3(int massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	int maximum = massiv[0][0];
	for (int i = 0; i < SIZE; i++) {
		if (maximum < massiv[i][i]) {
			maximum = massiv[i][i];
		}
	}
	return maximum;
}

double matrica3(double massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	double maximum = massiv[0][0];
	for (int i = 0; i < SIZE; i++) {
		if (maximum < massiv[i][i]) {
			maximum = massiv[i][i];
		}
	}
	return maximum;
}

char matrica3(char massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	char maximum = massiv[0][0];
	for (int i = 0; i < SIZE; i++) {
		if (maximum < massiv[i][i]) {
			maximum = massiv[i][i];
		}
	}
	return maximum;
}





int matrica4(int massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	int minimum = massiv[0][0];
	for (int i = 0; i < SIZE; i++) {
		if (minimum > massiv[i][i]) {
			minimum = massiv[i][i];
		}
	}
	return minimum;
}

double matrica4(double massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	double minimum = massiv[0][0];
	for (int i = 0; i < SIZE; i++) {
		if (minimum > massiv[i][i]) {
			minimum = massiv[i][i];
		}
	}
	return minimum;
}

char matrica4(char massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	char minimum = massiv[0][0];
	for (int i = 0; i < SIZE; i++) {
		if (minimum > massiv[i][i]) {
			minimum = massiv[i][i];
		}
	}
	return minimum;
}





void matrica5(int massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int q = 1; q < SIZE; q++) {
			for (int w = q; w > 0; w--) {
				if (massiv[i][w] < massiv[i][w - 1])
					swap(massiv[i][w], massiv[i][w - 1]);
				else break;
			}
		}
	}
}

void matrica5(double massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int q = 1; q < SIZE; q++) {
			for (int w = q; w > 0; w--) {
				if (massiv[i][w] < massiv[i][w - 1])
					swap(massiv[i][w], massiv[i][w - 1]);
				else break;
			}
		}
	}
}

void matrica5(char massiv[][SIZE2], const int SIZE) {
	int SIZE2 = sizeof(massiv[0]) / sizeof(massiv[0][0]);
	for (int i = 0; i < SIZE; i++) {
		for (int q = 1; q < SIZE; q++) {
			for (int w = q; w > 0; w--) {
				if (massiv[i][w] < massiv[i][w - 1])
					swap(massiv[i][w], massiv[i][w - 1]);
				else break;
			}
		}
	}
}














int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	const int SIZE = 10;
	int massiv1[SIZE] = { 3,7,4,9,1,5,2,6,0,8 };
	int a;
	cout << "Введите значение от 0 до 9" << endl;
	cin >> a;
	poisk(massiv1, SIZE, a);
	int b;
	cout << "Введите двоичное число" << endl;
	cin >> b;
	cout << dvavdesyat(b) << endl;


	int array[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int poisk;
	cout << "Введите значение от 1 до 10" << endl;
	cin >> poisk;
	cout << binar(array, SIZE, poisk) << endl << endl;



	int massiv2[SIZE2][SIZE2];
	double massiv3[SIZE2][SIZE2];
	char massiv4[SIZE2][SIZE2];
	matrica1(massiv2, SIZE2);
	matrica2(massiv2, SIZE2);
	cout << endl;
	matrica1(massiv3, SIZE2);
	matrica2(massiv3, SIZE2);
	cout << endl;
	matrica1(massiv4, SIZE2);
	matrica2(massiv4, SIZE2);
	cout << endl;
	cout << matrica3(massiv2, SIZE2) << endl;
	cout << matrica3(massiv3, SIZE2) << endl;
	cout << matrica3(massiv4, SIZE2) << endl;
	cout << endl;
	cout << matrica4(massiv2, SIZE2) << endl;
	cout << matrica4(massiv3, SIZE2) << endl;
	cout << matrica4(massiv4, SIZE2) << endl;
	cout << endl;

	matrica5(massiv2, SIZE2);
	matrica5(massiv3, SIZE2);
	matrica5(massiv4, SIZE2);

	matrica2(massiv2, SIZE2);
	cout << endl;
	matrica2(massiv3, SIZE2);
	cout << endl;
	matrica2(massiv4, SIZE2);
}