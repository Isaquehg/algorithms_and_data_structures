#include <iostream>

using namespace std;

struct treenode{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;//substituir treenode* por treenodeptr

void tInsere(treenodeptr &p, int x)
{
    if (p == NULL){ // insere na raiz
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else{
        if (x < p->info) // insere na subarvore esquerda
            tInsere(p->esq, x);
        else // insere na subarvore direita
            tInsere(p->dir, x);
    }
}

treenodeptr tPesq(treenodeptr p, int x)
{
    if (p == NULL) // elemento n~ao encontrado
        return NULL;
    else{
        if (x == p->info) // elemento encontrado na raiz
            return p;
        else{
            if (x < p->info) // procura na sub´arvore esquerda
                return tPesq(p->esq,x);
            else // procura na sub´arvore direita
                return tPesq(p->dir,x);
        }
    }
}

int main(){
    treenodeptr arvore = NULL;//pointer p raiz
    treenodeptr aux;
    int x;//aux p inserir dados

    tInsere(arvore, 14);
    tInsere(arvore, 4);
    tInsere(arvore, 18);

    x = 3;
    aux = tPesq(arvore, x);

    //output
    if(aux != NULL)
        cout << aux->info << endl;
    else
        cout << x << " nao encontrado" << endl;

    return 0;
}