#include <iostream>

using namespace std;

int main(){
    int n;//tamanho problema
    int x, i, j;//aux
    int cont = 0;//contador

    cout << "Digite o valor de n: " << endl;
    cin >> n;

    //f(n) = n^2

    /*for(i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            x = 2 * i;
            cont ++;
        }
    }
    cout << cont << " Repeticoes" << endl;*/

    //f(n) = n*log2(n)
    //nT = nE * nI(repeticoes do loop externo com interno)
    for(i = 0; i < n; i ++){
        j = 1;
        while(j < n){
            x = 2 * i;
            j = j * 2;
            cont ++;
        }
    }
    cout << cont << " Repeticoes" << endl;

    return 0;
}