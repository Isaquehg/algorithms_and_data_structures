#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string n1, n2;
    int i1, i2;

    getline(cin, n1);
    cin >> i1;
    cin.ignore();
    getline(cin, n2);
    cin >> i2;

    if (i1 > i2)
        cout << n1 << endl;
    else if (i2 > i1)
        cout << n2 << endl;
    else
        cout << "Idades iguais" << endl;

    return 0;
}