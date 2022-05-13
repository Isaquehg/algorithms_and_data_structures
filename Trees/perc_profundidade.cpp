/*
There are 3 depth path types:
    -Pre
    -In
    -Post
*/
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

void preOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        cout << arvore->info << endl;
        preOrdem(arvore->esq);
        preOrdem(arvore->dir);
    }
}

void emOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq);
        cout << arvore->info << endl;
        emOrdem(arvore->dir);
    }
}

void posOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        cout << arvore->info << endl;
    }
}

//contando numero de nos na arvore (podemos utilizar qualquer uma das funcoes de percurso em profundidade!)
void contaPreOrdem(treenodeptr arvore, int &n)
{
    if (arvore != NULL)
    {
        n ++;
        cout << arvore->info << endl;
        contaPreOrdem(arvore->esq, n);
        contaPreOrdem(arvore->dir, n);
    }
}
int contaNos(treenodeptr arvore){
    int n = 0;

    contaPreOrdem(arvore, n);

    return n;
}

int main(){
    treenodeptr arvore = NULL;//tree
    int x;//aux
    int n;//num de nos

    //input
    //Obs.: Inserir nós por niveis, da esquerda para a direita!
    cin >> x;
    while(x != 0){
        tInsere(arvore, x);
        cin >> x;
    }

    //percurso pre-ordem
    cout << "Pre-ordem:" << endl;
    preOrdem(arvore);

    //percurso em ordem
    cout << "Em ordem:" << endl;
    emOrdem(arvore);

    //precurso pos-ordem
    cout << "Pos ordem:" << endl;
    posOrdem(arvore);

    //contagem de nos da arvore atual
    n = contaNos(arvore);

    cout << "Numero de nos: " << n << endl;

    return 0;
}