#include <iostream>

using namespace std;

//O VETOR PRECISA ESTAR ORDENADO EM ORDEM CRESCENTE
int binaria(int vetor[], int tam, int num){
    bool passouaq = false;//verificar se achou o numero
    int sta, mid, end;//auxiliares
    sta = 0;
    end = tam;

    while((sta <= end) && (passouaq == false)){
        mid = (sta + end) / 2;
        if(num < vetor[mid]){
            end = mid - 1;
        }
        else{
            if(num > vetor[mid])
                sta = mid + 1;
            else
                passouaq = true;
        }
    }
    if(passouaq)
        return 0;
    else
        return -1;
}

int main(){
    int vet[100];//armazenar dados de entrada
    int id;//numero a procurar
    int y = 0;//numero de entradas(tamanho do vetor)
    int result;//atribuição da funcao

    //input
    cin >> vet[y];
    while(vet[y] != -1){
        y ++;
        cin >> vet[y];
    }
    cin >> id;
    //função
    result = binaria(vet, y, id);

    if(result == -1)
        cout << "Nao possui acesso" << endl;
    else
        cout << "Possui acesso" << endl;

    return 0;
}