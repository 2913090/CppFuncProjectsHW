#include <iostream>

int main()
{
    int chislo;
    using namespace std;
    setlocale(LC_ALL, "");
    cout << "Введите четырехзначное число\n";
    cin >> chislo;
    if (chislo / 1000 == 0 || chislo / 10000 > 0) {
        cout << "Введенные данные не корректны";
    }
    else {
        cout << (chislo / 1000) * 100 + ((chislo / 100) % 10) * 1000 + ((chislo / 10) % 10) + (chislo % 10) * 10;
    }
    }