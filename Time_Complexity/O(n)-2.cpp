//T(n) = n/2
#include <iostream>

using namespace std;

int main(){
    int i, j;//contadores
    int x;//aux
    int cont = 0;
    int n;//tamanho do problema

    cin >> n;

    for(i = 0; i < n; i += 2){
        x = i * 2;
        cont ++;
    }

    cout << cont << endl;

    return 0;
}