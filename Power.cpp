#include <iostream>

using namespace std;

int potencia(int base, int exp){
    if(exp == 0)
        return 1;
    else
        return base * potencia(base, exp - 1);
}

int main(){
    int a, b;//base e potencia

    cin >> a >> b;

    cout << potencia(a, b) << endl;

    return 0;
}