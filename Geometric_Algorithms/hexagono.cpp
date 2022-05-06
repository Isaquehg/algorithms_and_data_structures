//divide o poligono em varios triangulos
#include <iostream>
#include <cmath>
#include <iomanip>

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

float area_triangulo(ponto a, ponto b, ponto c){
    vetor ab;
    vetor ac;
    float area;
    ab = cria_vetor(a, b);
    ac = cria_vetor(a, c);
    area = fabs(vetorial(ab, ac)) / 2;
    return area;
}

//pontos devem estar ordenados radialmente
float area_poligono(ponto v[], int n){
    float area = 0;
    for(int i = 0; i < n - 2; i ++)
        area += area_triangulo(v[0], v[i + 1], v[i + 2]);
    return area;
}

int main(){
    int n = 6;//numero de entradas
    float result;//area do hexagono
    ponto v[100];

    //input
    for(int i = 0; i < n; i ++){
        cin >> v[i].x;
        cin >> v[i].y;
    }

    //area
    result = area_poligono(v, n);

    //output
    cout << fixed << setprecision(2);
    cout << "Area do escudo: " << result << endl;

    return 0;
}