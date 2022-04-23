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

int main(){
    int n;//qntdade de conj de pontos
    float result;
    ponto p1, p2, p3;

    //input
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;
        cin >> p3.x >> p3.y;
        result = area_triangulo(p1, p2, p3);
        if(result == 0)
            cout << "Nao formam triangulo" << endl;
        else
            cout << fixed << setprecision(2) << result << endl;
    }

    return 0;
}