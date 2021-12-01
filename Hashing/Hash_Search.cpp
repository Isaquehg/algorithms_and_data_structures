#include <iostream>

using namespace std;

struct dado{
    int k;//chave tabela
    int status;//status da tabela
};

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
//insertion
int hash_insert(dado t[], int m, int k, int c1, int c2){
    int i = 0;
    int j;
    do{
        j = hash1(k, i, m, c1, c2);//resultado sondagem
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
int hash_search(dado T[], int k, int m, int c1, int c2){
    int i = 0;//aux
    int j;//valor sondagem
    do{
        j = hash1(k, i, m, c1, c2);//sondar slot
        if(T[j].k == k)//se for o numero buscado
            return j;
        i ++;
    }while(T[j].status != 0 && i < m);
    return -1;
}

int main(){
    dado T[100];//hash table
    int tam;//tamanho tabela
    int chave;//chaves inseridas
    int key;//chave buscada
    int pos;//posicao da chave buscada
    int c1, c2;//aux

    //zerando tabela
    cin >> tam >> c1 >> c2;
    for(int i = 0; i < tam; i ++){
        T[i].status = 0;
        T[i].k = -1;
    }
    //inserindo valores
    cin >> chave;
    while(chave != 0){
        int x = hash_insert(T, tam, chave, c1, c2);
        cin >> chave;
    }
    //buscando chave
    cin >> key;
    pos = hash_search(T, key, tam, c1, c2);
    //output
    if(pos == -1)
        cout << "Chave " << key << " nao encontrada" << endl;
    else
        cout << "Chave " << key << " encontrada na posicao " << pos << endl;

    return 0;
}