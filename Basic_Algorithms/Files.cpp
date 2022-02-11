#include <iostream>
#include <fstream>
using namespace std;
struct pessoa{
    char nome[10];
    int id;
};
int main(){
    // DECLARANDO VARIAVEL PARA LEITURA DE DADOS
    ifstream leitura;
    leitura.open("dados.txt", ifstream::in);
    pessoa vet[10];
    int contador = 0;
    while(!leitura.eof()){
        leitura >> vet[contador].nome >> vet[contador].id;
        contador++;
    }
    for(int i = 0; i < contador; i += 2)
        cout << vet[i].nome << ' ' << vet[i].id << endl;
    leitura.close();
    // DECLARANDO VARIAVEL PARA ESCRITA DE DADOS
    ofstream escrita;
    char nome[15];
    escrita.open("dados2.txt", ofstream::out);
    for(int i = 0; i < contador; i++){
        escrita << vet[i].id << ' ' << vet[i].nome << endl;
    }
    escrita.close();
    return 0;
}