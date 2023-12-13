#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    int const SIZE1 = 4, SIZE2 = 5, MIN = 1, MAX = 9;
    int masiv[SIZE1][SIZE2], iteraciy;
    for (int i = 0; i < SIZE1; i++) {
        for (int j = 0; j < SIZE2; j++) {
            masiv[i][j] = MIN + rand() % (MAX - MIN + 1);
            cout << masiv[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "Enter number: ";
    cin >> iteraciy;
    for (int q = 0; q < iteraciy; q++) {
        for (int c, i = 0; i < SIZE1; i++) {
            c = masiv[i][SIZE2-1];
            for (int j = SIZE2-1; j > 0; j--) {
                masiv[i][j] = masiv[i][j-1];
            }
            masiv[i][0] = c;
        }
    }

    cout << endl;

    for (int i = 0; i < SIZE1; i++) {
        for (int j = 0; j < SIZE2; j++) {
            cout << masiv[i][j] << " ";
        }
        cout << endl;
    }
}