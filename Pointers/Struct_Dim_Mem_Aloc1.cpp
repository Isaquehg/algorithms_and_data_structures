#include <iostream>
#include <iomanip>

using namespace std;

struct dados
{
    int p1;
    int p2;
    int p3;
    int p4;
    float media;
};


int main(){
    dados *prova = NULL;//struct das notas

    prova = new dados;//alocacao
    //input notas
    cin >> prova->p1 >> prova->p2 >> prova->p3 >> prova->p4;
    //calc media
    prova->media = 0.0;
    prova->media += prova->p1;
    prova->media += prova->p2;
    prova->media += prova->p3;
    prova->media += prova->p4;
    prova->media /= 4.0;
    //output
    cout << fixed << setprecision(2);
    cout << prova->media << endl;

    delete prova;

    return 0;
}