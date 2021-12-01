#include <iostream>

using namespace std;

//h'(k) = k % m
//h(k, i, m) = (h'(k) + i) % m
int hash_aux(int k, int m){
    int result = k % m;//resultado da formula
    if(result < 0)
        result += m;
    return result;
}
int hash1(int k, int i, int m){
    int aux = hash_aux(k, m);//valores da auxiliar
    int h;//valor sondagem
    h = (aux + i) % m;
    return h;
}
int main(){
    int key;//chave
    int tam;//tamanho tabela hash
    int tent;//tentativas

    //input
    cin >> key >> tam;
    //tentativas e output
    for(tent = 0; tent < (tam); tent ++){
        cout << hash1(key, tent, tam) << " ";
    }

    return 0;
}