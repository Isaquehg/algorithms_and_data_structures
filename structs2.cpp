#include <iostream>

using namespace std;

struct dados{ //"cria" um novo tipo de variavel do tipo dados
    int idade;
    float peso;
};

int main(){
    dados atleta[3];//declarando variavel atleta de tipo dados

    atleta[0].idade = 18;
    atleta[0].idade = 67.5;

    return 0;
}