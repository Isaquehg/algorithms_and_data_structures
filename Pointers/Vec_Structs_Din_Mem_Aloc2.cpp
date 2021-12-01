#include <iostream>
#include <iomanip>

using namespace std;

struct dados{
    int n1;
    int n2;
    int n3;
    int n4;
    double med;
};

int main(){
    dados *provas = NULL;//struct para as notas e p media
    int tam;//numero de alunos
    int i;//aux
    double media = 0.0;//aux p media
    //input
    cin >> tam;
    provas = new dados[tam];
    for(i = 0; i < tam; i ++){
        cin >> provas[i].n1;
        cin >> provas[i].n2;
        cin >> provas[i].n3;
        cin >> provas[i].n4;
    }
    //calculando media por aluno
    for(i = 0; i < tam; i ++){
        provas[i].med = 0.0;
        provas[i].med += provas[i].n1;
        provas[i].med += provas[i].n2;
        provas[i].med += provas[i].n3;
        provas[i].med += provas[i].n4;
        provas[i].med /= 4.0;
    }
    //media geral
    for(i = 0; i < tam; i ++)
        media += provas[i].med;
    media /= (tam * 1.0);
    //output
    cout << fixed << setprecision(2);
    cout << media << endl;
    //limpando mem
    delete [] provas;

    return 0;
}