#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream arq;//declarando var (inputfile)
    char narq[50];//nome do arquivo
    int x[50];//vetor de armazenamento
    int i = 0;//contador
    double media = 0.0;//media das temperaturas
    
    //input
    cin.getline(narq, 50);
    //abertura do arquivo
    arq.open(narq, ifstream::in);
    //enquanto ñ chegar no final
    while(!arq.eof()){//(end of file)
        arq >> x[i];
        media += x[i];
        i ++;
    }
    //output
    cout << fixed << setprecision(1);
    cout << "Temperatura media: " << media / (i * 1.0) << " graus" << endl;
    //fechar arquivo
    arq.close();

    return 0;
}