#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string cidade;

    getline (cin, cidade);

    if(cidade == "Brasilia")
        cout << "35" << endl;
    else if(cidade == "Salvador")
        cout << "71" << endl;
    else if(cidade == "Sao Paulo")
        cout << "11" << endl;
    else if(cidade == "Rio de Janeiro")
        cout << "21" << endl;
    else if(cidade == "Juiz de Fora")
        cout << "32" << endl;
    else if(cidade == "Campinas")
        cout << "19" << endl;
    else if(cidade == "Vitoria")
        cout << "27" << endl;
    else if(cidade == "Belo Horizonte")
        cout << "31" << endl;
    else if(cidade == "Santa Rita do Sapucai")
        cout << "35" << endl;
    else
        cout << "DDD nao cadastrado" << endl;

    return 0;
}