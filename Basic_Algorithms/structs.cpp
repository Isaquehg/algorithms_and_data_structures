#include <iostream>

using namespace std;

struct dados{ //"cria" um novo tipo de variavel do tipo dados
    int idade;
    float peso;
};

int main(){
    dados atleta;//declarando variavel atleta de tipo dados

    //atribuindo valores aos campos da struct
    //atleta.idade = 18;
    //atleta.peso = 65.7;

    /*
    dados atleta[3];//declarando VETOR atleta de tipo dados
    atleta[0].idade = 18;
    atleta[1].idade = 67.5; */

    cin >> atleta.idade >> atleta.peso;
    
    cout << atleta.idade << endl;
    cout << atleta.peso << endl;

    return 0;
}