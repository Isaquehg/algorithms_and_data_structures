#include <iostream>

using namespace std;

void passou(float p1, float p2, int *result){
    float med = (p1 + p2) / 2;//media aritimetica notas
    if(med >= 60.0)
        *result = 1;
    else if(med < 60.0 && med >= 30.0)
        *result = 2;
    else
        *result = 3;
}

int main(){
    float p1, p2;//notas das provas
    int result;//passou = 1, NP3 = 2 ou reprovou = 3

    //input
    cin >> p1;
    cin >> p2;
    
    //verificar se passou
    passou(p1, p2, &result);

    //output
    if(result == 1)
        cout << "Aluno Aprovado!" << endl;
    else if(result == 2)
        cout << "Pegou NP3" << endl;
    else
        cout << "Aluno Reprovado" << endl;

    return 0;
}