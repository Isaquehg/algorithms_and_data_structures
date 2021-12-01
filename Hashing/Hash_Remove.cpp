#include <iostream>

using namespace std;

struct dado{
    int k;//chave tabela
    int status;//status da tabela
};

int hash_aux(int k, int m){
    int result = k % m;//formula
    if(result < 0)
        result += m;
    return result;
}
int hash_probe(int k, int i, int m){
    int aux = hash_aux(k, m);//valores da auxiliar
    int h;//valor sondagem
    h = (aux + i) % m;//formula
    return h;
}
//insertion
int hash_insert(dado t[], int m, int k){
    int i = 0;
    int j;
    do{
        j = hash_probe(k, i, m);//resultado sondagem
        if(t[j].status != 1){//se tiver espaco
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i ++;
    }while (i != m);
    return -1;
}
int hash_search(dado T[], int k, int m){
    int i = 0;//aux
    int j;//valor sondagem
    do{
        j = hash_probe(k, i, m);//sondar slot
        if(T[j].k == k)//se for o numero buscado
            return j;
        i ++;
    }while(T[j].status != 0 && i < m);
    return -1;
}
int hash_remove(dado t[], int m, int k){
    int j;//aux p search
    j = hash_search(t,k,m);
    if(j != -1){
       t[j].status = 2;
       t[j].k = -1;
       return 0;//consegui remover
    }
    else
       return -1;//k nao esta na tabela
}

int main(){
    dado T[100];//hash table
    int tam;//tamanho tabela
    int chave;//chaves inseridas
    int key;//chave a ser removida
    int x;//aux p atribuicao

    //zerando tabela
    cin >> tam;
    for(int i = 0; i < tam; i ++){
        T[i].status = 0;
        T[i].k = -1;
    }
    //inserindo valores
    cin >> chave;
    while(chave != 0){
        x = hash_insert(T, tam, chave);
        cin >> chave;
    }
    //removendo chave
    cin >> key;
    x = hash_remove(T, tam, key);

    for(int i = 0; i < tam; i ++)
        cout << T[i].k << " ";

    return 0;
}