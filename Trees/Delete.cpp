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

void posOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        cout << arvore->info << endl;
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
    int y;//numero a buscar

    //input
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

    return 0;
}