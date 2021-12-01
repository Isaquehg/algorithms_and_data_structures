#include <iostream>

using namespace std;

struct dados{//hash table
    int k;//chave
    int status;//status do slot
};
//using double hashing
//HASH FUNCTIONS
int h1(int k, int m){//probe1
    int h = k % m;
    if(h < 0)
        h += m;
    return h;
}
int h2(int k, int m){//probe2
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
int hash_insert(dados t[], int k, int m){//inserir dados
    int i = 0;
    int j;
    do{
        j = hash1(k, m, i);//resultado sondagem
        if(t[j].status != 1){//se tiver espaco
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i += 1;
    }while (i != m);
    return -1;
}
int hash_search(dados T[], int k, int m){//buscar dados
    int i = 0;//aux
    int j;//valor sondagem
    do{
        j = hash1(k, m, i);//sondar slot
        if(T[j].k == k)//se for o numero buscado
            return j;
        i ++;
    }while(T[j].status != 0 && i < m);
    return -1;
}
void hash_remove(dados t[], int k, int m){//remover dados
    int j;//aux p search
    j = hash_search(t,k,m);
    if(j != -1){
       t[j].status = 2;
       t[j].k = -1;
    }
}
void hash_show(dados T[], int m){//mostrar tabela
    for(int x = 0; x < m; x ++)
        if(x < (m - 1))
            cout << T[x].k << " ";
        else
            cout << T[x].k << endl;
}
void menu(dados T[], int op, bool &on, int m){
    int pes;//numero a pesquisar
    int del;//num a deletar
    int ins;//num a inserir
    int busca;//resultado da pesquisa
    int x;//aux insert
    /*
    OPERACOES
    1 - INSERIR
    2 - PESQUISAR
    3 - REMOVER
    4 - LISTAR
    5 - SAIR
    */
    switch (op)
    {
    case 1:
        cin >> ins;
        x = hash_insert(T, ins, m);
        break;
    case 2:
        cin >> pes;
        busca = hash_search(T, pes, m);
        cout << busca << endl;
        break;
    case 3:
        cin >> del;
        hash_remove(T, del, m);
        break;
    case 4:
        hash_show(T, m);
        break;
    default:
        on = false;
        break;
    }
}

int main(){
    dados T[100];//hash table
    int op;//operacao a ser feita
    int tam;//tamanho da tabela
    bool on = true;//programa continua

    //zerando tabela
    cin >> tam;
    for(int i = 0; i < tam; i ++){
        T[i].status = 0;
        T[i].k = -1;
    }
    //on/off
    while(on){
        cin >> op;
        menu(T, op, on, tam);
    }

    return 0;
}