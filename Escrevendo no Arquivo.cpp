#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream arq;//arquivo de texto
    ifstream ler;
    char narq[50];//nome do arquivo
    double num[100];//numero a entrar pelo usuario
    double mostrar[100];//numeros a mostrar do arquivo
    int x = 0, n;//contadores

    //input
    cin.getline(narq, 50);
    cin >> num[x];
    while(num[x] != 0){
        x ++;
        cin >> num[x];
    }
    //abertura do arquivo
    arq.open(narq, ofstream::out);
    //escrita
    for(n = 0; n < x; n ++){
        arq << num[n] << endl;
    }
    //fechar arquivo
    arq.close();
    //obtendo valores do arquivo
    //PODE USAR ARQ.GETLINE(NOME, 50), POR EXEMPLO
    ler.open(narq, ifstream::in);
    n = 0;
    while(!ler.eof()){
        ler >> mostrar[n];
        n ++;
    }
    //output
    for(n = 0; n < x; n ++){
        cout << mostrar[n] << " ";
    }
    //fechar arquivo
    ler.close();

    return 0;
}