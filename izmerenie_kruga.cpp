// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    float r;
    cout <<"Радиус круга = ";
    cin >> r;
    cout << "Площадь круга = " << r * r * 3.14 << "\n";
    cout << "Длина окружности = " << r * 6.28 << "\n";
    cout << "Диаметр круга = " <<  r * 2 << "\n";
}
