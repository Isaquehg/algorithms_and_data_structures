#include <iostream>

using namespace std;

void Insertion_Sort(int vetor[], int tam){
    int i, j;//auxiliares
    int chave;
    for(j = 1; j < tam; j ++){
        chave = vetor[j];
        i = j - 1;
        while((i >= 0) && (vetor[i] < chave)){
            vetor[i + 1] = vetor[i];
            i -= 1;
        }
        vetor[i + 1] = chave;
    }
}

int main(){
    int vet[100];//armazenamento da entrada
    int x;//contador
    int y = 0;//tamanho do vetor

    //input
    cin >> vet[y];
    while(vet[y] != 0){
        y ++;
        cin >> vet[y];
    }
    //atribuicao funcao
    Insertion_Sort(vet, y);
    //ouput
    x = 0;
    while(x < y){
        cout << vet[x] << " ";
        x ++;
    }
    cout << endl;

    return 0;
}