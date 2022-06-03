#include <iostream>
#include <cmath>

using namespace std;

struct ponto{
    float x;
    float y;
};

typedef ponto vetor;

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
        return 1; //se p estiver dentro do triangulo
    else if((s1 * s3 == -1) || (s1 * s2 == -1) || (s2 * s3 == -1))
        return -1; // p esta fora do triangulo
    else
        return 0; //p esta na borda
}

int main(){
    ponto h, v; //pontos do heroi e vilao
    ponto p1, p2;//pontos do raio
    int dentro_fora;//verificar se esta no triangulo

    //input
    cin >> h.x >> h.y;
    cin >> v.x >> v.y;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    //verificar se o vilao esta no raio
    dentro_fora = dentro_triangulo(h, p1, p2, v);

    //output
    if((dentro_fora == 1) || (dentro_fora == 0))
        cout << "Vilao derrotado" << endl;
    else
        cout << "Chame reforcos" << endl;

    return 0;
}