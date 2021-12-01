#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    //declarar a, b, c, delta, x1, x2
    double a, b, c, delta, x1, x2;

    //ler a, b, c
    cin >> a >> b >> c;

    //calcular Delta
    delta = pow(b,2) - (4*a*c);

    //validação e cáculo das raízes
    if (delta < 0 || a == 0)
        cout << "Impossivel" << endl;
    else{
        x1 = (-b+sqrt(delta))/(2*a);
        x2= (-b-sqrt(delta))/(2*a);
        cout << fixed << setprecision(5) << endl;
        cout << "X1: " << x1 << endl;
        cout << "X2: " << x2 << endl;
    }

    return 0;
}