#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    const int SIZE = 10;
    srand(time(NULL));

    int masiv11[SIZE], masiv12[SIZE / 2], masiv13[SIZE / 2];
    for (int q = 0; q < SIZE; q++)
        masiv11[q] = rand() % 10;
    for (int q = 0; q < SIZE; q++)
        cout << masiv11[q] << " ";
    for (int q = 0; q < SIZE / 2; q++)
        masiv12[q] = masiv11[q];
    for (int q = 0; q < SIZE / 2; q++)
        masiv13[q] = masiv11[q + SIZE / 2];
    cout << endl;
    for (int q = 0; q < SIZE / 2; q++)
        cout << masiv12[q] << " ";
    cout << endl;
    for (int q = 0; q < SIZE / 2; q++)
        cout << masiv13[q] << " ";

    cout << endl;

    int masiv21[SIZE], masiv22[SIZE], masiv23[SIZE];
    for (int q = 0; q < SIZE; q++)
        masiv21[q] = rand() % 10;
    for (int q = 0; q < SIZE; q++)
        masiv22[q] = rand() % 10;
    for (int q = 0; q < SIZE; q++)
        masiv23[q] = masiv21[q] + masiv22[q];
    cout << endl;
    for (int q = 0; q < SIZE / 2; q++)
        cout << masiv21[q] << " ";
    cout << endl;
    for (int q = 0; q < SIZE / 2; q++)
        cout << masiv22[q] << " ";
    cout << endl;
    for (int q = 0; q < SIZE / 2; q++)
        cout << masiv23[q] << " ";

    cout << endl;
    
    //int masiv31[7], sred = 0, sum = 0, count = 0;
    //for (int q = 0; q < 7; q++) {
    //    cout << "Сколько долларов вы потратили за  " << q + 1 << "-й день?\n";
    //    cin >> masiv31[q];
    //}
    //for (int q = 0; q < 7; q++)
    //    sum += masiv31[q];
    //sred = sum/7;
    //cout << "В среднем вы тратите " << sred << " долларов в день\n";
    //cout << "Всего вы потратили " << sum << " долларов\n";
    //for (int q = 0; q < 7; q++)
    //    if (masiv31[q] > 100) {
    //        count++;
    //        switch (q+1) {
    //        case 1:
    //            cout << "понедельник\n";
    //            break;
    //        case 2:
    //            cout << "вторник\n";
    //            break;
    //        case 3:
    //            cout << "среда\n";
    //            break;
    //        case 4:
    //            cout << "четверг\n";
    //            break;
    //        case 5:
    //            cout << "пятница\n";
    //            break;
    //        case 6:
    //            cout << "суббота\n";
    //            break;
    //        case 7:
    //            cout << "воскресенье\n";
    //            break;
    //        }
    //    }
    //cout << "вы потратили больше 100 долларов " << count << " раз\n";

    //cout << endl;

    const float EURODOLLAR = 1.0524, PROCENT = 0.05;
    float masiv41[12], masiv42[12] = {};
    int a;
    cout << "Введите сумму на депозите в евро\n";
    cin >> masiv41[0];
    for (int q = 0; q < 11; q++) {
        masiv41[q + 1] = masiv41[q] * (PROCENT + 1);
        masiv42[q + 1] = masiv41[q] * PROCENT;
    }
    for (int q = 0; q < 12; q++)
        cout << masiv41[q] << endl;
    cout << endl;
    for (int q = 0; q < 12; q++)
        cout << masiv42[q] << endl;
    cout << "Введите номер месяца (1-12)\n";
    cin >> a;
    if (masiv42[a - 1] * EURODOLLAR >= 500) {
        cout << "Вы можете снять " << masiv42[a - 2] * EURODOLLAR / 2 << " долларов";
    }

}