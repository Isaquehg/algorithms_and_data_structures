#include <iostream>
#include <iomanip>

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

void preOrdem (treenodeptr arvore, float &media)
{
    if (arvore != NULL)
    {
        media += arvore->info;
        preOrdem(arvore->esq, media);
        preOrdem(arvore->dir, media);
    }
}

void contaPreOrdem(treenodeptr arvore, int &n)
{
    if (arvore != NULL)
    {
        n ++;
        contaPreOrdem(arvore->esq, n);
        contaPreOrdem(arvore->dir, n);
    }
}
int contaNos(treenodeptr arvore){
    int n = 0;

    contaPreOrdem(arvore, n);

    return n;
}

//destruir arvore
void tDestruir (treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    arvore = NULL;
}

int main(){
    treenodeptr arvore = NULL;//tree
    float media = 0.0;//media dos elementos
    int x;//aux
    int n;//numero de nos

    //input
    cin >> x;
    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    //percurso pre-ordem
    preOrdem(arvore, media);

    //contagem de nos
    n = contaNos(arvore);

    //output
    cout << fixed << setprecision(2);
    cout << "Media: " << media/n << endl;

    //destruindo
    tDestruir(arvore);

    return 0;
}