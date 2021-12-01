#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct dados{
    int codigo; // codigo do produto
    int quantidade; // quantidade em estoque
    float preco; // preco unitario
};

void quickSort(dados vetor[], int tamanho, int i, int j){
    dados transicao;//struct auxiliar
    int esq,dir,pivo;//parametros de divisao do vetor
    esq = i;
    dir = j;
    pivo = vetor[(int)round((esq + dir)/2.0)].codigo;//definindo pivo como termo central
    do{
        while (vetor[esq].codigo < pivo)
            esq++;
        while (vetor[dir].codigo > pivo)
            dir--;
        if (esq <= dir){
            transicao = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = transicao;
            esq ++;
            dir --;
        }
    } while (esq <= dir);
    if (dir-i >= 0)
        quickSort(vetor,tamanho,i,dir);
    if (j-esq >= 0)
        quickSort(vetor,tamanho,esq,j);
}

int main(){
    dados loja[100];//vetor armazenamento
    int n;//numero de cadastros
    
    //input
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> loja[i].codigo >> loja[i].quantidade >> loja[i].preco;
    }
    
    //ordenando
    quickSort(loja, n, 0, n);

    //output
    cout << fixed << setprecision(2);
    for(int i = 0; i < n; i ++){
        cout << "Codigo: " << loja[i].codigo << endl;
        cout << "Quantidade em estoque: " << loja[i].quantidade << endl;
        cout << "Preco unitario: R$ " << loja[i].preco << endl;
        cout << endl;
    }

    return 0;
}