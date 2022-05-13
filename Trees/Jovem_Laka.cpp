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

void preOrdem (treenodeptr arvore, int x, int &pre)
{
    if (arvore != NULL)
    {
        if(arvore->info != x){
            pre ++;
            preOrdem(arvore->esq, x, pre);
            preOrdem(arvore->dir, x, pre);
        }
    }
}

void emOrdem (treenodeptr arvore, int x, int &em)
{
    if (arvore != NULL)
    {
        if(arvore->info != x){
            emOrdem(arvore->esq, x, em);
            em ++;
            emOrdem(arvore->dir, x, em);
        }
    }
}

void posOrdem (treenodeptr arvore, int x, int &pos)
{
    if (arvore != NULL)
    {
        if(arvore->info != x){
            posOrdem(arvore->esq, x, pos);
            posOrdem(arvore->dir, x, pos);
            pos ++;
        }
    }
}

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
    int x;//aux e cidade a procurar
    int pre, pos, em;//menor distancia de cada
    int n;//num de nos

    pre = 0;
    pos = 0;
    em = 0;

    //input
    cin >> x;
    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }
    cin >> x;

    //percurso pre-ordem
    preOrdem(arvore, x, pre);
    cout << "Pre-ordem:" << pre << endl;

    //percurso em ordem
    emOrdem(arvore, x, em);
    cout << "Em ordem:" << em << endl;

    //precurso pos-ordem
    posOrdem(arvore, x, pos);
    cout << "Pos ordem:" << pos << endl;

    //output
    if((pre < em) && (pre < pos))
        cout << "Pre" << endl;
    else if((em < pre) && (em < pos))
        cout << "Em" << endl;
    else
        cout << "Pos" << endl;

    return 0;
}