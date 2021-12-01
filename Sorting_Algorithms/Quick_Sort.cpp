#include <iostream>
#include <cmath>

using namespace std;
//i é posição inicial e j é o tamanho - 1
void quickSort(int vetor[], int tamanho, int i, int j)
{
    int trab, esq, dir, pivo;
    esq = i;
    dir = j;
    pivo = vetor[(int)round((esq + dir) / 2.0)];
    do
    {
        while (vetor[esq] < pivo)
            esq++;
        while (vetor[dir] > pivo)
            dir--;
        if (esq <= dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    }
    while (esq <= dir);
    if (dir - i >= 0)
        quickSort(vetor, tamanho, i, dir);
    if (j - esq >= 0)
        quickSort(vetor, tamanho, esq, j);
}

int main(){
    int vet[100];//vetor de armazenamento
    int y;//aux
    int x = 0;//contador
    int tam;//tamanho

    //input
    cin >> y;
    while(y != -1){
        vet[x] = y;
        x ++;
        cin >> y;
    }
    tam = x;
    x -= 1;
    //ordenando
    quickSort(vet, tam, 0, x);

    //output
    for(x = 0; x < tam; x ++)
        cout << vet[x] << " ";

    return 0;
}