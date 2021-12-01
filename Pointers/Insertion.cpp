#include <iostream>
using namespace std;

int main(){
    int *vet;//armazenamento
    int *p;//pointer p in
    int *q;//pointer p out
    int tam;//tamanho vetor
    int i;//aux
    int x;//num a inserir
    //input
    cin >> tam;
    vet = new int[tam];//alocando
    p = vet;
    for(i=0;i<tam;i++){
    cin >> *p;//vet[i]
    p++;//iterando pelo vetor
    }
    //output
    q = vet;
    for(i = 0; i < tam; i ++){
        cout << *q << " ";
        q ++;
    }

    delete [] vet;

    return 0;
}