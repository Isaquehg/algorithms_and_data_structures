#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <list>

using namespace std;

struct ponto{
    float x;
    float y;
};

struct reta{
    ponto a;
    ponto b;
};

typedef ponto vetor;
typedef reta segmento;

vetor cria_vetor(ponto a, ponto b){
        vetor ab;
        ab.x = b.x - a.x;
        ab.y = b.y - a.y;
        return ab;
}

float vetorial(vetor a, vetor b){
    float resultado;
    resultado = a.x*b.y - a.y*b.x;

    return resultado;
}

float area_triangulo(ponto a, ponto b, ponto c){
    vetor ab;
    vetor ac;
    float area;
    ab = cria_vetor(a, b);
    ac = cria_vetor(a, c);
    area = fabs(vetorial(ab, ac)) / 2;
    return area;
}

int sentido(ponto a, ponto b, ponto c){
    vetor ab;
    vetor ac;
    float vet;
    ab = cria_vetor(a, b);
    ac = cria_vetor(a, c);
    vet = vetorial(ab, ac);
    if(vet > 0)
        return 1;
    else if(vet < 0)
        return -1;
    else
        return 0;
}

//funcao p comparar dois pontos durante a ordenacao
bool cmp(ponto a, ponto b){
    float angA = atan2(a.y, a.x);
    float angB = atan2(b.y, b.x);
    if(angA == angB){ //se os angulos forem iguais, desempata pelo mais longe
        float distA = sqrt(pow(a.x, 2) + pow(a.y, 2));
        float distB = sqrt(pow(b.x, 2) + pow(b.y, 2));
        return distA > distB; //primeiro ode maior distancia
    }
    else{
        return angA < angB; //primeiro o de menor angulo
    }
}

//ordenar pontos de acordo com o angulo
void ordenacao_angulo(ponto p[], int n){
    ponto pivot;//sera o ponto mais abaixo e mais a esquerda
    int pos_pivot;

    //encontrar ponto mais abaixo
    pivot = p[0];
    pos_pivot = 0;
    for(int i = 1; i < n; i ++){
        if(p[i].y < pivot.y){
            pivot = p[i];
            pos_pivot = i;
        }
        else if(p[i].y == pivot.y && p[i].x < pivot.x){
            pivot = p[i];
            pos_pivot = i;
        }
    }

    //coloca pivot na posicao zero do vetor
    p[pos_pivot] = p[0];
    p[0] = pivot;

    //desloca pivot para (0,0) e os demais pontos em relacao ao pivot
    for(int i = 0; i < n; i ++){
        p[i].x -= pivot.x;
        p[i].y -= pivot.y;
    }

    //ordenando
    sort(p + 1, p + n, cmp);

    //desloca os pontos para as posicoes originais
    for(int i = 0; i < n; i ++){
        p[i].x += pivot.x;
        p[i].y += pivot.y;
    }

}

//penultimo da pilha
ponto next_to_top(list <ponto> pilha){
    pilha.pop_back();
    return pilha.back();
}

//encontra o fecho convexo de um conjunto de pontos
//retorna uma lista com os pontos que compoem o fecho convexo
list <ponto> Graham_Scan(ponto p[], int n){
    list <ponto> pilha;

    //ordenando
    ordenacao_angulo(p, n);

    //adiciona os tres primeiros pontos
    pilha.push_back(p[0]);
    pilha.push_back(p[1]);
    pilha.push_back(p[2]);

    //criando o poligono
    int i = 3;
    while(i < n){
        //curva a esquerda: adiciona
        if(sentido(next_to_top(pilha), pilha.back(), p[i]) == 1){
            pilha.push_back(p[i]);
            i ++;
        }
        //curva a direita: remove
        else
            pilha.pop_back();
    }
    return pilha;
}

int main(){
    ponto v[100];
    int n;
    list <ponto> fecho_convexo;

    //input
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> v[i].x;
        cin >> v[i].y;
    }

    //criando a constelacao
    fecho_convexo = Graham_Scan(v, n);

    //output
    cout << fecho_convexo.size() << " lados" << endl;

    return 0;
}