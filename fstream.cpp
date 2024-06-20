#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream out;
    out.open("text.txt");
    if (out.is_open()) {
        out << "Hello world" << endl;
    }
    out.close();








    ifstream in("text.txt");
    string line = "";
    if (in.is_open()) {
        while (getline(in,line)) {
            cout << line << endl;
        }
    }
    in.close();

}