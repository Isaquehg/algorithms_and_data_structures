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

int preOrdem (treenodeptr arvore, int x, int &i)
{
    if (arvore != NULL)
    {
        if(arvore->info == x){
            return i;
        }
        else
            i ++;
            preOrdem(arvore->esq, x, i);
            preOrdem(arvore->dir, x, i);
    }
}
int emOrdem (treenodeptr arvore, int x, int &j)
{
    if (arvore != NULL)
    {
        if(arvore->info == x){
            return j;
        }
        else
            emOrdem(arvore->esq, x, j);
            j ++;
            emOrdem(arvore->dir, x, j);
    }
}

int posOrdem (treenodeptr arvore, int x, int &k)
{
    if (arvore != NULL)
    {
        if(arvore->info == x){
            return k;
        }
        else
            posOrdem(arvore->esq, x, k);
            posOrdem(arvore->dir, x, k);
            k ++;
    }
}

int main(){
    treenodeptr arvore = NULL;//tree
    int x;//aux e cidade a procurar
    int pre, pos, em;//menor distancia de cada
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
    int i_pre = 0;//aux
    int i_em = 0;//aux
    int i_pos = 0;//aux
    pre = preOrdem(arvore, x, i_pre);
    cout << "Pre-ordem:" << pre << endl;

    //percurso em ordem
    em = emOrdem(arvore, x, i_em);
    cout << "Em ordem:" << em << endl;

    //precurso pos-ordem
    pos = posOrdem(arvore, x, i_pos);
    cout << "Pos ordem:" << pos << endl;
    cout << endl;

    //output
    if((pre < em) && (pre < pos))
        cout << "Pre" << endl;
    else if((em < pre) && (em < pos))
        cout << "Em" << endl;
    else
        cout << "Pos" << endl;

    return 0;
}