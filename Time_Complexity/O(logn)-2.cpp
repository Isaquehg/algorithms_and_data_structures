//T(n) = log2(n)
#include <iostream>

using namespace std;

int main(){
    int i, j;//contadores
    int x;//aux
    int cont;
    int n;//tamanho do problema

    cin >> n;

    cont = 0;
    i = n;
    while(i > 1){
        x = i * 2;
        i /= 2;
        cont ++;
    }

    cout << cont << endl;

    return 0;
}