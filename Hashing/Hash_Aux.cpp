#include <iostream>

using namespace std;

//h(k) = k % m
int hash_aux(int k, int m){
    int result = k % m;//resultado da formula
    if(result < 0)
        result += m;
    return result;
}
int main(){
    int key;//chave hash
    int tam;//tamanho
    int x = 0;//aux
    int result;//retorno funcao

    cin >> key >> tam;
    while(key != 0 && tam != 0){
        cout << hash_aux(key, tam) << endl;;
        x ++;
        cin >> key >> tam;
    }


    return 0;
}