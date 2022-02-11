#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream arq;
    int x = 2;

    //abertura do arquivo
    //para adicionar(append):
    //arq.open("larry.txt", ofstream::app);
    arq.open("larry.txt", ofstream::out);
    //escrita
    arq << "Larry, Darry Merry" << endl;
    arq << x;

    arq.close();

    return 0;
}