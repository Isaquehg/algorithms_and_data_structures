#include <iostream>

using namespace std;

struct treenode{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;

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

void emOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->dir);
        cout << arvore->info << endl;
        emOrdem(arvore->esq);
    }
}



int main(){
    treenodeptr arvore = NULL;//tree
    int x;//aux

    //input
    cin >> x;
    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    //percurso pre-ordem
    emOrdem(arvore);

    return 0;
}