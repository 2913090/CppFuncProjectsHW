#include <iostream>
using namespace std;
int main()
{
    int strok, opozdaniy,zarplata;
    short vibor;
    setlocale(LC_ALL, "");
    cout << "Вы хотите ввести: \nжелаемый доход и количество опозданий(1), \nколичество строк кода и желаемый объем зарплаты(2), \nколичество строк кода и количество опозданий(3).\n";
    cin >> vibor;
    switch (vibor){
    case 1:
        cout << "Введите желаемый доход\n";
        cin >> zarplata;
        cout << "Введите количество опозданий\n";
        cin >> opozdaniy;
        cout << "Нужно напечатать " << (zarplata + opozdaniy * 20) * 2 << " строк кода.";
        break;
    case 2:
        cout << "Введите количество строк кода\n";
        cin >> strok;
        cout << "Введите желаемый доход\n";
        cin >> zarplata;
        ((strok / 100 * 50 - zarplata) / 20 >= 0) ? cout << "Можно опоздать " << (strok / 100 * 50 - zarplata) / 20 << " раз." : cout << "Нет возможных решений.";
        break;
    case 3:
        cout << "Введите количество строк кода\n";
        cin >> strok;
        cout << "Введите количество опозданий\n";
        cin >> opozdaniy;
        (strok / 100 * 50 - opozdaniy * 20 >= 0) ? cout << "Будет заработано " << strok / 100 * 50 - opozdaniy * 20 << " $." : cout << "Зарплата в 0.";
        break;
    default:
        cout << "Введенные данные некорректны";
    }
}
