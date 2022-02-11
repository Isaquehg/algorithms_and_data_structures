#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct dados{
    char nome[100];//nome do civil
    char ec;//estado civil
    int sexo;//sexos
    int idade;//idades
};
int main(){
    dados civis[100];
    char velho[50];//nome do mais velho
    int x = 0;//contador
    int maisvelho = 0;//idade do mais velho
    int n;//numero de inputs
    double casados = 0.0;//num de casados
    double media = 0.0;

    //input
    cin.getline(civis[x].nome, 100);
    while(strcmp(civis[x].nome, "sair") != 0){
        cin >> civis[x].sexo;//sexo
        while(civis[x].sexo != 1 && civis[x].sexo != 2){
            cin >> civis[x].sexo;
        }
        cin >> civis[x].ec;//estado civil
        while(civis[x].ec != 'C' && civis[x].ec != 'S' && civis[x].ec != 'V' && civis[x].ec != 'D'){
            cin >> civis[x].ec;
        }
        cin >> civis[x].idade;//idade
        x ++;
        cin.ignore();
        cin.getline(civis[x].nome, 100);//nome
    }
    n = x;
    //contabilizando casados, idade media e pessoa mais velha
    for(x = 0; x < n; x ++){
        if(civis[x].ec == 'C')//num de casados
            casados += 1.0;
        media += (double)civis[x].idade;//media de idades
        if(civis[x].idade > maisvelho && civis[x].sexo == 1){
            maisvelho = civis[x].idade;
            strcpy(velho, civis[x].nome);
        }
    }
    //output
    cout << fixed << setprecision(2);
    cout << "Porcentagem de pessoas casadas: " << (casados / n) * 100.0 << "%" << endl;
    cout << "Idade media da populacao: " << media / n * 1.0 << " anos" << endl;
    cout << "Nome e idade do homem mais velho: " << velho << " " << maisvelho << " anos" << endl;
    
    return 0;
}