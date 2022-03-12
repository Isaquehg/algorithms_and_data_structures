#include <iostream>

using namespace std;

int potencia(int a, int n){
    if(n == 0)
        return 1;
    else
        return a * potencia(a, n - 1);
}

int main(){
    int a;//base
    int n;//potencia
    int result;//resultado

    //input
    cin >> a >> n;

    //resultado
    result = potencia(a, n);

    cout << result << endl;

    return 0;
}