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

int main(){
    treenodeptr arvore = NULL;//pointer p raiz
    int x;//aux p inserir dados

    tInsere(arvore, 14);
    tInsere(arvore, 4);
    tInsere(arvore, 18);

    //output
    cout << "A Raiz da Arvore e: " << arvore->info << endl;
    cout << "O filho a direita e: " << (arvore->dir)->info << endl;
    cout << "O filho a esquerda e: " << (arvore->esq)->info << endl;


    return 0;
}