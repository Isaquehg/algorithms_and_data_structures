#include <iostream>

using namespace std;

struct dados{
    int k;//chave
    int status;//status do slot
};

int h1(int k, int m){//probe 1
    int h = k % m;
    if(h < 0)
        h += m;
    return h;
}
int h2(int k, int m){//probe 2
    int hh = 1 + (k % (m - 1));
    if(hh < 0){
        hh += m;
    }
    return hh;
}
int hash1(int k, int m, int i){//double hashing
    int dhash = (h1(k, m) + (i * h2(k, m))) % m;
    return dhash;
}
int hash_search(dados T[], int k, int m){//buscar dados
    int i = 0;//aux
    int j;//valor sondagem
    do{
        j = hash1(k, m, i);//sondar slot
        if(T[j].k == k)//se for o numero buscado
            return j;//encontrado
        i ++;
    }while(T[j].status != 0 && i < m);
    return -1;//nao encontrado
}
int hash_remove(dados T[], int k, int m){
    int j;//aux p search
    j = hash_search(T, k, m);
    if(j != -1){
       T[j].status = 2;
       T[j].k = -1;
       return 0;//removido
    }
    else
       return -1;//nao esta na tabela
}
int main(){
    dados T[100];
    int tam;//tamanho da tabela
    int i, y;//aux
    int x;//numero a remover
    int result;//var p remocao

    //zerando tabela
    cin >> tam;
    for(i = 0; i < tam; i ++){
        T[i].status = 0;
        T[i].k = -1;
    }
    //input
    i = 0;
    cin >> y;
    while(y != 0){
        T[i].k = y;
        i ++;
        cin >> y;
    }
    cin >> x;//numero a remover
    //removendo
    result = hash_remove(T, x, tam);
    //output
    for(i = 0; i < tam; i ++)
        cout << T[i].k << " ";

    return 0;
}