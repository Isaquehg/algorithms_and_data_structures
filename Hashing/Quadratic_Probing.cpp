#include <iostream>

using namespace std;

/*
h'(k, m) = k % m
h(k, i, m) = (h'(k, m) + c1 * i + c2 * i²) % m
*/
int hash_aux(int k, int m){
    int result = k % m;//resultado da formula
    if(result < 0)
        result += m;
    return result;
}
int hash1(int k, int i, int m, int c1, int c2){
    int result = hash_aux(k, m);//valor da auxiliar
    int h = (result + c1 * i + c2 * (i * i)) % m; //formula
    return h;
}
int main(){
    int key;//chave
    int c1, c2;//aux
    int i;//tentativas
    int tam;//tamanho
    int result;//atribuicao func

    //input
    cin >> key >> tam >> c1 >> c2;

    //probing
    for(i = 0; i < tam; i ++){
        result = hash1(key, i, tam, c1, c2);
        cout << result << " ";
    }
    return 0;
}