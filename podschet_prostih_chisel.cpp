#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int a, b, c = 0;
    bool e = 1;
    cout << "Введите диапозон\n";
    cin >> a >> b;
    if (a > b)swap(a, b);
    for (int q = a; q <= b; q++) {
        e = 1;
        for (int w = 2; q > w; w++) {
            if (q % w == 0) {
                e = 0;
                break;
            }
            else
                cout << q << "\t" << w << "\t" << c << "\n";
        }
        if (e == 1)c++;
    }
    cout << "В заданном диапозоне " << c << " простых значений.";
}