#include <iostream>
using namespace std;
bool chetnost(int a) {
    return a % 2;
}
bool polindrom(int a) {
    int c=0, b = a;
    while (b > 0) {
        c = c * 10 + b % 10;
        b /= 10;
    }
    return (a == c) ? 1: 0;
}
long long factorial(int a) {
    int otvet = 1;
    for (int i = 2; i <= a; i++) {
        otvet *= i;
    }
    return otvet;
}
int main()
{
    setlocale(LC_ALL, "");
    int vvod1;
    cout << "Введите число\n";
    cin >> vvod1;
    (chetnost(vvod1)) ? cout << "Введенное число нечетное" : cout << "Введенное число четное";
    cout << endl;



    int vvod2;
    cout << "Введите число\n";
    cin >> vvod2;
    (polindrom(vvod2)) ? cout << "Введенное число является полиндромом" : cout << "Введенное число не является полиндромом";
    cout << endl;



    int vvod3;
    cout << "Введите число\n";
    cin >> vvod3;
    cout << factorial(vvod3);
}