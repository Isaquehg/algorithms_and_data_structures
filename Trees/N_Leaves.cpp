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

void emOrdem (treenodeptr arvore, int &n_folhas)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->dir, n_folhas);
        emOrdem(arvore->esq, n_folhas);
        if((arvore->dir == NULL) && (arvore->esq == NULL))
            n_folhas ++;
    }
}

int main(){
    treenodeptr arvore = NULL;//tree
    int x;//aux
    int n_folhas = 0;//numero de folhas

    //input
    cin >> x;
    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    //percurso em ordem
    emOrdem(arvore, n_folhas);

    //output
    cout << n_folhas << endl;

    return 0;
}