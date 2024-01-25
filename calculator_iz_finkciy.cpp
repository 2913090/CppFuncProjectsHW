#include <iostream>
using namespace std;


int slozh(int a, int b) {
	return a + b;
}
int vichit(int a, int b) {
	return a - b;
}
int umnojenie(int a, int b) {
	return a * b;
}
int delenie(int a, int b) {
	if (b != 0) {
		return a / b;
	}
	cout << "error";
	return 0;
}








float slozh1(float a, float b) {
	return a + b;
}
float vichit1(float a, float b) {
	return a - b;
}
float umnojenie1(float a, float b) {
	return a * b;
}
float delenie1(float a, float b) {
	if (b != 0) {
		return a / b;
	}
	cout << "error";
	return 0;
}



int calculator(int a, int b, char q) {
	switch (q) {
	case '+':
		return slozh(a, b);
	case '-':
		return vichit(a, b);
	case '*':
		return umnojenie(a, b);
	case '/':
		return delenie(a, b);
	default:
		cout << "error";
		return 0;
	}
}





float calculator(float a, float b, char q) {
	switch (q) {
	case '+':
		return slozh1(a, b);
	case '-':
		return vichit1(a, b);
	case '*':
		return umnojenie1(a, b);
	case '/':
		return delenie1(a, b);
	default:
		cout << "error";
		return 0;
	}
}




int main()
{

	float a, b;
	char q;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	cout << "Enter operand(+ - * /): ";
	cin >> q;
	if (q == '+' or q == '-' or q == '*' or q == '/') {
		cout << calculator(a, b, q);
	}
	else {
		cout << "Incorrect input values";
	}










}