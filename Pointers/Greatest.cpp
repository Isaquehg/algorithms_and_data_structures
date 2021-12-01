#include <iostream>

using namespace std;

int main(){
    int *vet = NULL;//vetor
    int tam;//tamanho vetor
    int maior = -100000;//maior num
    int *p;//pointer input
    int *m;//pointer p maior
    int i;//aux
    //input
    cin >> tam;
    vet = new int[tam];
    p = vet;
    for(i = 0; i < tam; i ++){
        cin >> *p;
        p ++;
    }
    //encontrando o maior
    m = vet;
    for(i = 0; i < tam; i ++){
        if(maior < *m)//se for menor q o elemento atual
            maior = *m;
        m ++;
    }
    //output
    cout << maior << endl;
    //garbage collection
    delete [] vet;

    return 0;
}