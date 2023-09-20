#include <iostream>

int main()
{
    int chisla[7],q;
    using namespace std;
    setlocale(LC_ALL, "");
    cout << "Введите семь целых чисел\n";
    cin >> chisla[0] >> chisla[1] >> chisla[2] >> chisla[3] >> chisla[4] >> chisla[5] >> chisla[6];
    for (int w{ 1 }; w < 7; w++) {
        q = chisla[0];
        if (chisla[w] > q) {
            q = chisla[w];
        }
    }
    cout << "наибольшее число из заданных - " << q;
    }