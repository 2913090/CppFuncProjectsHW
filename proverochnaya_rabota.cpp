#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    //1

    //int max11, max12, max13, max14;
    //cout << "Введите 4 числа\n";
    //cin >> max11 >> max12 >> max13 >> max14;
    //if (max11 > max12 && max11 > max13 && max11 > max14)
    //    cout << "Максимальное из введеных чисел: " << max11;
    //else if (max12 > max13 && max12 > max14)
    //    cout << "Максимальное из введеных чисел: " << max12;
    //else if (max13 > max14)
    //    cout << "Максимальное из введеных чисел: " << max13;
    //else
    //    cout << "Максимальное из введеных чисел: " << max14;






    //2

    //int a, b, n;
    //cout << "Введите начало диапозона\n";
    //cin >> a;
    //cout << "Введите конец диапозона\n";
    //cin >> b;
    //cout << "Введите количество значений\n";
    //cin >> n;
    //if (a > b) swap(a, b);
    //if (b - a < n) n = b - a;
    //for (int j = 0, i = a; j < n; i++, j++)
    //    cout << endl << i;
    //cout << endl;







    //3

    //float max3;
    //cout << "Введите значение\n";
    //cin >> max3;
    //if (max3 < 0) cout << "Введенное значение меньше 0";
    // else{
    //for (float i = 0; i < max3; i += 0.25)
    //    cout << endl << i;
    //}
    //cout << endl;






    //4

    //int znach4, count = 0, sum = 0;
    //do {
    //    cout << "\nВведите значение\n";
    //    cin >> znach4;
    //    count++;
    //    sum += znach4;
    //} while (znach4 != 0);
    //count--;
    //cout << "Среднее арифметическое введенных вами чисел = " << sum / count << endl;








    //5

    //char bukva;
    //cout << "Введите символ\n";
    //cin >> bukva;
    //if (bukva >= 'a' && bukva <= 'z'|| bukva >= 'A' && bukva <= 'Z')
    //    cout << "Введеный вами символ является английской буквой";
    //else
    //    cout << "Введеный вами символ не является английской буквой";
    //cout << endl;







    //6

    //int masiv6[10], min = 7, max = 18;
    //for (int i = 0; i < 10; i++) {
    //    masiv6[i] = min + rand() % (max + 1 - min);
    //    cout << masiv6[i] << endl;
    //}




    //7

    //cout << endl;
    //int chet_masiv6[10] = {};
    //for (int i = 0, j = 0; i < 10; i++) {
    //    if (masiv6[i] % 2 == 0) {
    //        chet_masiv6[j++] = masiv6[i];
    //    }
    //}
    //for (int i = 0; i < 10; i++) {
    //    cout << chet_masiv6[i] << endl;
    //}










    //8

    //int dlina;
    //cout << "Введите длину стороны квадрата\n";
    //cin >> dlina;
    //if (dlina % 2 == 0) dlina++;
    //for (int i = 0; i < dlina; i++) cout << " 0";
    //cout << endl;
    //for (int i = 0; i < (dlina - 2) / 2; i++) {
    //    cout << " 0";
    //    for (int j = 0; j < (dlina - 2) / 2; j++)
    //        cout << "  ";
    //    cout << " 0";
    //    for (int j = 0; j < (dlina - 2) / 2; j++)
    //        cout << "  ";
    //    cout << " 0\n";
    //}
    //for (int i = 0; i < dlina; i++) cout << " 0";
    //cout << endl;
    //for (int i = 0; i < (dlina - 2) / 2; i++) {
    //    cout << " 0";
    //    for (int j = 0; j < (dlina - 2) / 2; j++)
    //        cout << "  ";
    //    cout << " 0";
    //    for (int j = 0; j < (dlina - 2) / 2; j++)
    //        cout << "  ";
    //    cout << " 0\n";
    //}
    //for (int i = 0; i < dlina; i++) cout << " 0";
    //cout << endl;












    //9

    //int const DLINA = 10, MIN = 1, MAX = 10;
    //int masiv9[DLINA];
    //for (int i = 0; i < DLINA; i++) {
    //    masiv9[i] = MIN + rand() % (MAX + 1 - MIN);
    //    if (masiv9[i]%2==0)
    //        cout << masiv9[i] << endl;
    //}







    //10

    /*int masiv10[5][4], min = 10, max = 99;
    int maximum = min, cormax, sum = 0, minimum = max;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            masiv10[i][j] = min + rand() % (max + 1 - min);
            cout << masiv10[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (maximum < masiv10[i][j]) {
                maximum = masiv10[i][j];
                cormax = j+1;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (minimum > masiv10[i][j]) minimum = masiv10[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            sum += masiv10[i][j];
        }
    }

    cout << "\nМаксимальное значение массива: " << maximum << "\nМинимальное значение массива: " << minimum << "\nСумма всех значений массива:" << sum << "\nНомер столбца с наибольшим значением:" << cormax;
*/
}