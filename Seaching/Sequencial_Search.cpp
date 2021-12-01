#include <iostream>

using namespace std;

int sequencial(int vet[], int tam, int x){//func p retornar posicao no vetor do num
    bool passouaq = false;//tem o numero no vetor
    int pos;//posicao no vetor
    for(int y = 0; y < tam; y ++){
        if(x == vet[y]){//se achar
            pos = y;
            passouaq = true;
        }
    }
    if(passouaq == true){
        return pos;
    }
    else{
        return -1;
    }
}
int main(){
    int vet[100];//vetor a ser preenchido
    int tam = 0;//contador e tamanho do vetor
    int num;//numero a ser procurado
    int result;//resultado da funcao

    //input
    cin >> vet[tam];
    while(vet[tam] != -1){
        tam ++;
        cin >> vet[tam];
    }
    cin >> num;
    //busca
    result = sequencial(vet, tam, num);
    //output
    if(result != -1){
        cout << num << " encontrado na posicao " << result << endl;
    }
    else{
        cout << num << " nao foi encontrado" << endl;
    }

    return 0;
}