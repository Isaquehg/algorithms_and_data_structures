#include <iostream>

using namespace std;

void Bubble_Sort(int vetor[], int tam){
    int i, j;//contadores
    int trab;//transicao
    int limite;//limita a analise da troca
    bool troca = true;//verifica se e necessario trocar

    //ordenando
    limite = tam - 1;
    while(troca){
        troca = false;
        for(i = 0; i < limite; i ++){
            if(vetor[i] > vetor[i + 1]){//se estiver desordenado
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;
                troca = true;
            }
        }
        limite = j;
    }
}

int main(){
    int vet[100];//armazenamento
    int x = 0;//num entradas
    int y;//contador

    //input
    cin >> vet[x];
    while(x < 9){
        x ++;
        cin >> vet[x];
    }
    //ordenando
    Bubble_Sort(vet, x);

    //output
    for(y = 0; y < x; y ++){
        cout << vet[y] << " ";
    }

    return 0;
}