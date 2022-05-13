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
        emOrdem(arvore->esq);
        cout << arvore->info << " ";
        emOrdem(arvore->dir);
    }
}

//funcao p encontrar o menor valor da subarvore direita p substituir na raiz
treenodeptr tMenor(treenodeptr &raiz)
{
    treenodeptr t;

    t = raiz;
    if (t->esq == NULL) // encontrou o menor valor
    {
        raiz = raiz->dir;
        return t;
    }
    else // continua a busca na sub´arvore esquerda
        return tMenor(raiz->esq);
}

//remover nos
int tRemove(treenodeptr &raiz, int x)
{
    treenodeptr p;
    if (raiz == NULL) //arvore vazia
        return 1;
    if (x == raiz->info)
    {
        p = raiz;
        if (raiz->esq == NULL) //a raiz nao tem filho esquerdo
            raiz = raiz->dir;
        else{
            if (raiz->dir == NULL) //a raiz nao tem filho direito
            raiz = raiz->esq;
            else //a raiz tem ambos os filhos
            {
                p = tMenor(raiz->dir);
                raiz->info = p->info;
            }
        }
        delete p;
        return 0;
    }
    else{
        if (x < raiz->info)
            return tRemove(raiz->esq,x);
        else
            return tRemove(raiz->dir,x);
    }
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
    int x;//aux
    int y;//numero a buscar

    //input
    cin >> x;
    while(x != 0){
        tInsere(arvore, x);
        cin >> x;
    }
    cin >> y;

    //delete
    int i;//aux
    i = tRemove(arvore, y);
    while(i != 1){
        i = tRemove(arvore, y);
    }

    //output nos restantes
    emOrdem(arvore);

    //destruindo
    tDestruir(arvore);

    return 0;
}