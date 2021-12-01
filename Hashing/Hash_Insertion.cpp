#include <iostream>

using namespace std;

struct dado{
    int status;//verificar se está ocupado
    int k;//chave
};

//Hash Auxiliar
int hash_aux(int k, int m){
    int result = k % m;//resultado da formula
    if(result < 0)
        result += m;
    return result;
}
//Hash Probe
int hash1(int k, int i, int m){
    int aux = hash_aux(k, m);//valores da auxiliar
    int h;//valor sondagem
    h = (aux + i) % m;
    return h;
}
//insertion
int hash_insert(dado t[], int m, int k){
    int i = 0;
    int j;
    do{
        j = hash1(k, i, m);//resultado sondagem
        if(t[j].status != 1){//se tiver espaco
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    }while (i != m);
    return -1;
}

int main(){
    dado T[100];//hash table
    int tam;//tamanho
    int chave = 1;
    int i, x;//aux

    //zerando tabela
    cin >> tam;
    for(i = 0; i < tam; i ++){
        T[i].status = 0;
        T[i].k = -1;
    }
    //inserindo valores
    cin >> chave;
    while(chave != 0){
        x = hash_insert(T, tam, chave);
        cin >> chave;
    }
    //output tabela
    for(i = 0; i < tam; i ++){
        cout << T[i].k << " ";
    }

    return 0;
}