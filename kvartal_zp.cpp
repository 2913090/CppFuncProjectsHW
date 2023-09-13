#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    float zp1, zp2, zp3;
    cout << "Зарплата за 1-й месяц = ";
    cin >> zp1;
    cout << "Зарплата за 2-й месяц = ";
    cin >> zp2;
    cout << "Зарплата за 3-й месяц = ";
    cin >> zp3;
    cout << "Зарплата за квартал " << zp1+zp2+zp3;

}
