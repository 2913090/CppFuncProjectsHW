#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int const SIZE1 = 5, SIZE2 = 8;
    int studentsMarks[SIZE1][SIZE2], ind_max_avg;
    float sum = 0, sum2 = 0, max_avg = 0;
    for (int q = 0; q < SIZE1; q++) {
        for (int w = 0; w < SIZE2; w++) {
            studentsMarks[q][w] = 2 + rand() % 4;
        }
    }

    cout << "\tмат\tфиз\tангл\tрус\tлит\tобж\tист\tгеогр\n";

    for (int q = 0; q < SIZE1; q++) {
        cout << "Ст " << q + 1 << "\t";
        sum2 = 0;
        for (int w = 0; w < SIZE2; w++) {
            cout << studentsMarks[q][w] << "\t";
            sum2 += studentsMarks[q][w];
        }
        cout << "\t Средняя оценка " << sum2 / (SIZE2) << endl;
        if (max_avg < sum2) {
            max_avg = sum2;
            ind_max_avg = q;
        }
    }

    for (int q = 0; q < SIZE1; q++) {
        for (int w = 0; w < SIZE2; w++) {
            sum += studentsMarks[q][w];
        }
    }
    cout << "Средняя оценка: " << sum / (SIZE1 * SIZE2);
    cout << "\nВысший средний бал " << max_avg / (SIZE2) << " у студента " << ind_max_avg + 1;








    cout << endl;
    cout << endl;

    int const  VISOTA = 4, DLINA = 5;
    int max = 99, min = 10;
    int massiv[VISOTA][DLINA], summa = 0, cord_max_x, cord_max_y, cord_min_x, cord_min_y, 
        max_stroka = min * DLINA, cord_max_stroka, min_stroka = max * DLINA, cord_min_stroka, 
        max_stolb = min * DLINA, min_stolb = max * DLINA, cord_max_stolb, cord_min_stolb;
    int max_znach = min, min_znach = max;
    for (int q = 0; q < VISOTA; q++) {
        for (int w = 0; w < DLINA; w++) {
            massiv[q][w] = min + rand() % (max + 1 - min);
            if (max_znach < massiv[q][w]) { 
                max_znach = massiv[q][w]; 
                cord_max_x = w;
                cord_max_y = q;
            }
            if (min_znach > massiv[q][w]) {
                min_znach = massiv[q][w];
                cord_min_x = w;
                cord_min_y = q;
            }
        }
    }


    for (int sum = 0, q = 0; q < VISOTA; q++, sum=0) {
        for (int w = 0; w < DLINA; w++) {
            cout << massiv[q][w] << "\t";
            sum += massiv[q][w];
        }
        summa += sum;
        cout << "| " << sum << endl;
        if (max_stroka < sum) {
            max_stroka = sum;
            cord_max_stroka = q;
        }
        if (min_stroka > sum) {
            min_stroka = sum;
            cord_min_stroka = q;
        }
    }

    for (int w = 0; w < DLINA; w++) cout << "--------";
    cout << "+\n";

    for (int sum = 0, q = 0; q < DLINA; q++, sum = 0) {
        for (int w = 0; w < VISOTA; w++) {
            sum += massiv[w][q];
        }
        cout << sum << "\t";
        if (max_stolb < sum) {
            max_stolb = sum;
            cord_max_stolb = q;
        }
        if (min_stolb > sum) {
            min_stolb = sum;
            cord_min_stolb = q;
        }
    }
    cout << "  " << summa;

    



    cout << endl;
    cout << "\nМаксимальное значение: " << max_znach << " ["<< cord_max_x << ";" << cord_max_y << "]" << endl;
    cout << "Минимальное значение: " << min_znach << " ["<< cord_min_x << ";" << cord_min_y << "]" << endl;
    cout << "Максимальная сумма в строках: " << max_stroka << " [" << cord_max_stroka << "]" << endl;
    cout << "Минимальная сумма в строках: " << min_stroka << " [" << cord_min_stroka << "]" << endl;
    cout << "Максимальная сумма в столбцах: " << max_stolb << " [" << cord_max_stolb << "]" << endl;
    cout << "Минимальная сумма в столбцах: " << min_stolb << " [" << cord_min_stolb << "]" << endl;
}