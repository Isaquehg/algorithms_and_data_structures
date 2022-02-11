#include <iostream>

using namespace std;

int main(){
    int n;//tamanho problema
    int x, i;//aux
    int cont = 0;//contador

    cout << "Digite o valor de n: " << endl;
    cin >> n;
    
    //f(n) = log2(n)
    
    i = 1;
    while(i < n){
        x = 2 * i;
        i = i * 2;
        cont ++;
    }
    cout << cont << " Repeticoes" << endl;

    return 0;
}