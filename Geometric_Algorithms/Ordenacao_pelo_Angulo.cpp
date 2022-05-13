#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

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
}

float escalar(vetor a, vetor b){
    float resultado;
    resultado = a.x*b.x + a.y*b.y;
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

int dentro_triangulo(ponto a, ponto b, ponto c, ponto p){
    int s1, s2, s3;
    s1 = sentido(a, b, p);
    s2 = sentido(b, c, p);
    s3 = sentido(c, a, p);
    if(s1 == s2 && s2 == s3)
        return 1;
    else if((s1 * s3 == -1) || (s1 * s2 == -1) || (s2 * s3 == -1))
        return -1;
    else
        return 0;
}

//verificar se o ponto esta no segmento ou nao
bool ponto_segmento(segmento s, ponto p){
    //se for colinear
    if(sentido(s.a, s.b, p) != 0)
        return false;
    //se for crescente
    else if(p.x > s.a.x && p.x < s.b.x)
        return true;
    //se for decrescente
    else if(p.x < s.a.x && p.x > s.b.x)
        return true;
    //direita
    else if(p.y < s.a.y && p.y > s.b.y)
        return true;
    //esquerda
    else if(p.y > s.a.y && p.y < s.b.y)
        return true;
    else
        return false;
}

//pontos devem estar ordenados radialmente
float area_poligono(ponto v[], int n){
    float area = 0;
    for(int i = 0; i < n - 2; i ++)
        area += area_triangulo(v[0], v[i + 1], v[i + 2]);
    return area;
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

int main(){
    int n;//qntdade de conjunto de pontos
    float result;
    ponto p1, p2, p3;

    //input
    

    return 0;
}