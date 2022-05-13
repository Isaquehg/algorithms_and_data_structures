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
        emOrdem(arvore->esq);
    }
}

treenodeptr pMenor (treenodeptr arvore){
    treenodeptr menor;
    if(arvore != NULL){
        menor = pMenor(arvore->esq);
        if(menor == NULL)
            return arvore;
    }
}
treenodeptr pMaior(treenodeptr arvore){
    treenodeptr maior;
    if(arvore != NULL){
        maior = pMaior(arvore->dir);
        if(maior == NULL)
            return arvore;
    }
}

int main(){
    treenodeptr arvore = NULL;//tree
    treenodeptr result_maior;
    treenodeptr result_menor;
    int x;//aux

    //input
    //Obs.: Inserir nós por niveis, da esquerda para a direita!
    cin >> x;
    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    //output
    result_maior = pMaior(arvore);
    result_menor = pMenor(arvore);
    cout << result_menor->info << " e " << result_maior->info << endl;

    return 0;
}