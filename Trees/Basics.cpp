#include <iostream>

using namespace std;

struct treenode{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;//substituir treenode* por treenodeptr

int main(){
    treenodeptr arvore = NULL;//pointer p raiz
    int x;//aux p inserir dados

    /*
    1. Criar nó
    2. Colocar a informação
    3. Apontar os filhos p NULL
    */

    x=14;//raiz
    arvore = new treenode;//alocar memoria
    arvore->info = x;//preencher info
    arvore->esq = NULL;
    arvore->dir = NULL;

    x = 4;//filho esquerdo da raiz
    arvore->esq = new treenode;
    (arvore->esq)->info = x;
    (arvore->esq)->esq = NULL;
    (arvore->dir)->dir = NULL;
    
    x = 18;//filho direita da raiz
    arvore->dir = new treenode;
    (arvore->dir)->info = x;
    (arvore->dir)->dir = NULL;
    (arvore->esq)->esq = NULL;

    //output
    cout << "A Raiz da Arvore e: " << arvore->info << endl;
    cout << "O filho a direita e: " << (arvore->dir)->info << endl;
    cout << "O filho a esquerda e: " << (arvore->esq)->info << endl;


    return 0;
}