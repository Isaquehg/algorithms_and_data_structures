#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int cod;//codigo do país
    double val;//quantidade a converter

    cin >> val >> cod;

    cout << fixed << setprecision(2);

    switch(cod){
        case 1:
            cout << "R$ " << val * 3.86 << endl;
            break;
        case 2:
            cout << "R$ " << val * 3.77 << endl;
            break;
        case 3:
            cout << "R$ " << val * 4.41 << endl;
            break;
        case 4:
            cout << "R$ " << val * 0.19 << endl;
            break;
        case 5:
            cout << "R$ " << val * 5.00 << endl;
            break;
    }

    return 0;
}