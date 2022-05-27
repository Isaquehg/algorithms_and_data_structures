#include <iostream>
#include <list>

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

//Percurso em nivel
void emNivel(treenodeptr t){
    treenodeptr n;
    list <treenodeptr> q;

    if(t != NULL){
        q.push_back(t);
        while(!q.empty()){
            n = *q.begin();
            q.pop_front();
            if(n -> esq != NULL)
                q.push_back(n->esq);
            if(n->dir != NULL)
                q.push_back(n->dir);
            cout << n->info << " ";
        }
        cout << endl;
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

    //input
    cin >> x;
    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    //percurso em largura
    emNivel(arvore);

    //destruindo
    tDestruir(arvore);

    return 0;
}