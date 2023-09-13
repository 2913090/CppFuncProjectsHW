// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    float o1, o2, o3, o4;
    cout << "Оценка студента за 1 четверть = ";
    cin >> o1;
    cout << "Оценка студента за 2 четверть = ";
    cin >> o2;
    cout << "Оценка студента за 3 четверть = ";
    cin >> o3;
    cout << "Оценка студента за 4 четверть = ";
    cin >> o4;
    cout << "Оценка студента за год " << round((o1+o2+o3+o4)/4);

}
