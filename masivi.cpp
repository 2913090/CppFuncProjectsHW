#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int masiv[10], pribil[12];
    //1
    for (int q = 0; q < 10; q++) {
        masiv[q] = 1 + rand() % 10;
        cout << masiv[q] << "\t";
    }
    int min=masiv[0], max=masiv[0];
    for (int q = 0; q < 10; q++) {
        if (masiv[q] > max) max = masiv[q];
        if (masiv[q] < min) min = masiv[q];
    }
    cout << "\nмаксимальное значение: " << max;
    cout << "\nминимальное значение: " << min;
    //2
    int a, b, menshe, sum=0;
    cout << "\nВведите границы диапозона через пробел\n";
    cin >> a >> b;
    if (a > b) swap(a, b);
    for (int q = 0; q < 10; q++) {
        masiv[q] = a + rand() % (b+1-a);
        cout << masiv[q] << "\t";
    }
    cout << "\nСложить элементы массива, которые меньше: ";
    cin >> menshe;
    for (int q = 0; q < 10; q++) {
        if (masiv[q] < menshe) sum += masiv[q];
    }
    cout << "\nСумма элементов массива меньше " << menshe << ": " << sum;
    //3
    int mesyats1, mesyats2;
    for (int q = 0; q < 12; q++) {
        cout << "\nВведите прибыль за " << q + 1 << "-й месяц\n";
        cin >> pribil[q];
    }
    cout << "\nВведите диапозон в месяцах (1-12) через пробел";
    cin >> mesyats1 >> mesyats2;
    if (mesyats1 > mesyats2) swap(mesyats1, mesyats2);
    min = pribil[mesyats1-1];
    max = pribil[mesyats1-1];
    for (int q = mesyats1-1; q < mesyats2-1; q++) {
        if (pribil[q] > max)max = pribil[q];
        if (pribil[q] < min)min = pribil[q];
    }
    cout << "\nМаксимальный заработок за месяц в указанном диапозоне составляет " << max;
    cout << "\nМинимальный заработок за месяц в указанном диапозоне составляет " << min << endl;
    //4
    int const N=10;
    int ind_min, ind_max;
    float array[N], sum_otr = 0, proizv1 = 1, proizv2 = 1, sum_minus = 0, min1, max1;
    cout << endl;
    for (int q = 0; q < N; q++) {
        array[q] = (-100 + rand() % 201) / 10.00;
        cout << array[q] << "\t";
    }
    for (int q = 0; q < N; q++) {
        if (array[q] < 0) sum_otr += array[q];
    }
    cout << "\nСумма отрицательных чисел = " << sum_otr;
    min1 = array[0];
    max1 = array[0];
    for (int q = 0; q < N; q++) {
        if (array[q] < min1) {
            min1 = array[q];
            ind_min = q;
        }
        if (array[q] > max1){
            max1 = array[q];
            ind_max = q;
        }
    }
    for (int q = 0; q < N; q++)
        proizv1 *= array[q];
    cout << "\nПроизведение элементов, находящихся между минимальным и максимальным элементами = " << proizv1;
    for (int q = 0; q < N; q += 2)
        proizv2 *= array[q];
    cout << "\nПроизведение элементов с четными номерами = " << proizv2;
    int perviy = 0, posledniy = N;
    for (int q = 0; q < N; q++)
        if (array[q] < 0){
            perviy = q;
            break;
        }
    for (int q = N; q > 0; q--)
        if (array[q] < 0){
            posledniy = q;
            break;
        }
    for (int q = perviy; q < posledniy; q++)
        sum_minus += array[q];
    cout << "\nСумма элементов, находящихся между первым и последним отрицательными элементами = " << sum_minus;
}