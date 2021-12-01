#include <iostream>

using namespace std;

int main(){
    int *vet;//vet p armazenamento
    int *p;//input pointer
    int *q;//pointer p positivos e pares
    int i;//aux;
    int tam;//tamanho
    int pospar = 0;//numeros positivos e pares
    //input
    cin >> tam;
    vet = new int[tam];
    p = vet;
    for(i = 0; i < tam; i ++){
        cin >> *p;
        p ++;
    }
    //encontrando positivos e pares
    q = vet;
    for(i = 0; i < tam; i ++){
        if((*q > 0) && (*q % 2 == 0))
            pospar ++;
        q ++;
    }
    //output
    cout << pospar << endl;

    delete [] vet;

    return 0;
}