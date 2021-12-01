#include <iostream>
#include <iomanip>

using namespace std;

double media(int notas[], int alunos){
    double m = 0.0;//media
    int i;//counter

    for(i = 0; i < alunos; i ++){
        m += notas[i];
    }
    m = m / alunos * 1.0;
    return m;
}
int nAbaixo(int notas[], int alunos, double med){
    int abaixo = 0;//abaixo da media
    for(int i = 0; i < alunos; i ++){
        if(notas[i] < med)
            abaixo ++;
    }
    return abaixo;
}
int nAcima(int notas[], int alunos, double med){
    int acima = 0;//acima da media
    for(int i = 0; i < alunos; i ++){
        if(notas[i] >= med)
            acima ++;
    }
    return acima;
}
int main(){
    int i;//contador
    int n;//numero de alunos
    int provas[100];//notas dos alunos
    int aprovado, desaprovado;//alunos com e sem media
    double result;//resultado

    //input
    cin >> n;
    for(i = 0; i < n; i ++)
        cin >> provas[i];
    
    //atribuição
    result = media(provas, n);
    aprovado = nAcima(provas, n, result);
    desaprovado = nAbaixo(provas, n, result);

    //output
    cout << fixed << setprecision(2);
    cout << "Media da turma = " << result << endl;
    cout << "Alunos com nota abaixo da media: " << desaprovado << endl;
    cout << "Alunos com nota acima da media: " << aprovado << endl;

    return 0;
}