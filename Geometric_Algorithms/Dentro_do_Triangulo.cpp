#include <iostream>
#include <cmath>
#include <iomanip>

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

/*
Se o produto vetorial entre dois vetores for positivo, a reta sera para a esquerda
Se for positivo, a reta sera p direita
Senao, sera linear
*/
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

/*
Se o ponto estiver a esquerda de todos os lados, ele esta dentro do triangulo
Se estiver a direita de todos lados, esta fora do triangulo
Senao, esta em uma das bordas.
*/
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
    ponto p1, p2, p3, p4;//pontos dados
    int dentro_fora;//verificar se esta no triangulo

    //input
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;

    //calculando se p[4] esta dentro do triangulo
    dentro_fora = dentro_triangulo(p1, p2, p3, p4);

    //output
    if(dentro_fora == 1)
        cout << "Ataquem" << endl;
    else
        cout << "Preparem-se" << endl;

    return 0;
}