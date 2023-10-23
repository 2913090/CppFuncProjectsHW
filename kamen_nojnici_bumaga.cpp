#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int igrok = 0, komp = 0, komphod, igrokhod;
    while (igrok < 5 && komp < 5) {
        srand((unsigned)time(NULL));
        komphod = 1 + (rand() % 3);
        cout << "Камень(1), ножницы(2) или бумага(3)\n";
        cin >> igrokhod;
        switch (igrokhod) {
        case 1:
            switch (komphod) {
            case 1:
                cout << "Ничья\n";
                break;
            case 2:
                cout << "Вы победили\n";
                igrok++;
                break;
            case 3:
                cout << "Вы проиграли\n";
                komp++;
                break;
            }
            break;
        case 2:
            switch (komphod) {
            case 1:
                cout << "Вы проиграли\n";
                komp++;
                break;
            case 2:
                cout << "Ничья\n";
                break;
            case 3:
                cout << "Вы победили\n";
                igrok++;
                break;
            }
            break;
        case 3:
            switch (komphod) {
            case 1:
                cout << "Вы победили\n";
                igrok++;
                break;
            case 2:
                cout << "Вы проиграли\n";
                komp++;
                break;
            case 3:
                cout << "Ничья\n";
                break;
            }
            break;
        }
        cout << "Компьютер-" << komp << ":Игрок-" << igrok << "\n";
    }
    (igrok==5)? cout << "Победа игрока": cout << "Победа компьютера";
}
