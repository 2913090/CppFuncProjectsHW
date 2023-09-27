#include <iostream>
using namespace std;
int main()
{
    float vremya;
    short oper;
    setlocale(LC_ALL, "");
    cout << "Сколько минут длился ваш разговор?\n";
    cin >> vremya;
    if (vremya >= 0) {
        cout << "Ваш мобильный оператор:(1,2,3)\n";
        cin >> oper;
        switch (oper) {
        case 1:
            cout << "Ваш разговор стоит " << vremya * 2 << " рублей";
            break;
        case 2:
            cout << "Ваш разговор стоит " << vremya * 1.6 << " рублей";
            break;
        case 3:
            cout << "Ваш разговор стоит " << vremya * 2.3 << " рублей";
            break;
        default:
            cout << "Введенные данные некорректны";
        }
    }
    else
        cout << "Введенные данные некорректны";
}